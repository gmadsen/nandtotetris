#include "Parser.hpp"

#include <string>
#include <iostream>
#include <unordered_map>

class CodeWriter
{
public:
    CodeWriter(std::string name) 
    {
        m_segment_map["local"] = "LCL";
        m_segment_map["argument"] = "ARG";
        m_segment_map["this"] = "THIS";
        m_segment_map["that"] = "THAT";
        m_segment_map["temp"] = "TEMP";

        auto dot_pos = name.rfind('.');
        auto slash_pos = name.rfind('/');
        m_file_name = name.substr(slash_pos + 1, dot_pos - slash_pos - 1); 
        out_file.open(name.substr(0,dot_pos) + ".asm");
    }

    ~CodeWriter()
    {
        out_file.close();
    }

    void writeArithmetic(std::string command)
    {
        if (command == "add")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "M=M+D" << "\n";
            incrementStackPointer(out_file);
            out_file <<  "// finished adding \n\n"; 
        }
        else if (command == "sub")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "M=M-D" << "\n";
            incrementStackPointer(out_file);
            out_file <<  "// finished substraction \n\n";  
 
        }
        else if (command == "neg")
        {
            goToNextValueMem(out_file);
            out_file << "M=-M" << "\n";
            incrementStackPointer(out_file);
            out_file << "//finished neg \n\n";
        }
        else if (command == "eq")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "D=M-D" << "\n";
            atTrueVar(out_file);
            out_file << "D;JEQ" << "\n";

            out_file << "//entering false branch \n";
            out_file << "@0" << "\n";
            out_file << "D=A" << "\n";
            replaceCurrentTopMemWithD(out_file);
            jumpToExitConditionalVar(out_file);

            out_file << "//entering true branch \n";
            addTrueLabel(out_file);
            out_file << "@0" << "\n";
            out_file << "D=!A" << "\n";
            replaceCurrentTopMemWithD(out_file);
            addExitConditionalLabel(out_file);

            incrementStackPointer(out_file);
            out_file << "//finished eq \n\n";
        }
        else if (command == "gt")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "D=M-D" << "\n";
            atTrueVar(out_file);
            out_file << "D;JGT" << "\n";

            out_file << "//entering false branch \n";
            out_file << "@0" << "\n";
            out_file << "D=A" << "\n";
            replaceCurrentTopMemWithD(out_file);
            jumpToExitConditionalVar(out_file);

            out_file << "//entering true branch \n";
            addTrueLabel(out_file);
            out_file << "@0" << "\n";
            out_file << "D=!A" << "\n";
            replaceCurrentTopMemWithD(out_file);
            addExitConditionalLabel(out_file);
            incrementStackPointer(out_file);
            out_file << "//finished gt \n\n";

        }
        else if (command == "lt")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "D=M-D" << "\n";
            atTrueVar(out_file);
            out_file << "D;JLT" << "\n";

            out_file << "//entering false branch \n";
            out_file << "@0" << "\n";
            out_file << "D=A" << "\n";
            replaceCurrentTopMemWithD(out_file);
            jumpToExitConditionalVar(out_file);

            out_file << "//entering true branch \n";
            addTrueLabel(out_file);
            out_file << "@0" << "\n";
            out_file << "D=!A" << "\n";
            replaceCurrentTopMemWithD(out_file);

            addExitConditionalLabel(out_file);
            incrementStackPointer(out_file);
            out_file << "//finished lt \n\n";
        }
        else if (command == "and")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "M=M&D" << "\n";

            incrementStackPointer(out_file);
            out_file << "//finished and \n\n";
        }
        else if (command == "or")
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            goToNextValueMem(out_file);
            out_file << "M=M|D" << "\n";
            incrementStackPointer(out_file);
            out_file << "//finished or \n\n";
 
        }
        else if (command == "not")
        {
            goToNextValueMem(out_file);
            out_file << "M=!M" << "\n";
            incrementStackPointer(out_file);
            out_file << "//finished not \n\n";
 
        }

    }

    void writePushPop(CommandType command, std::string segment, int index)
    {

        if (command == CommandType::C_PUSH) 
        {
            if (segment == "constant") 
            {
                out_file << "@" << std::to_string(index) << "\n";
                out_file << "D=A" << "\n"; 
                replaceCurrentTopMemWithD(out_file);
                incrementStackPointer(out_file);
 
            }
            else if (segment == "static")
            {
                out_file << "@" << m_file_name << "." << m_static_map[index] << "\n";
                out_file << "D=M" << "\n";
                replaceCurrentTopMemWithD(out_file);
                incrementStackPointer(out_file);
            }
            else
            {
                std::string asm_segment;
                if (segment == "pointer")
                {
                    asm_segment = (index == 0) ? "THIS" : "THAT";
                    out_file << "@" << asm_segment << "\n";
                    out_file << "D=M" << "\n";

                }
                else
                {
                    asm_segment = m_segment_map[segment];
                    addSegmentAddressToR14(out_file, asm_segment, index); 
                    out_file << "A=D" << "\n";
                    out_file << "D=M" << "\n";
                }
                replaceCurrentTopMemWithD(out_file);
                incrementStackPointer(out_file);
            }

           out_file << "// finished pushing: " << segment << " " << std::to_string(index) << "\n\n"; 

        }
        else if (command == CommandType::C_POP)
        {
            std::string asm_segment;
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            if (segment == "pointer")
            {
                asm_segment = (index == 0) ? "THIS" : "THAT";
                out_file << "@" << asm_segment << "\n";
                out_file << "M=D" << "\n";
            }
            else if (segment == "static")
            {
                auto var_idx = m_static_map.find(index);
                if (var_idx == m_static_map.end())
                {
                    auto cur_size = m_static_map.size();
                    m_static_map.insert({index, cur_size});  ///TODO this probably isn't needed
                }
                out_file << "@" << m_file_name << "." << m_static_map[index] << "\n";
                out_file << "M=D" << "\n";
            }
            else
            {
                out_file << "@R13" << "\n";
                out_file << "M=D" << "\n";
                asm_segment = m_segment_map[segment];
                addSegmentAddressToR14(out_file, asm_segment, index);
                out_file << "@R13" << "\n";
                out_file << "D=M" << "\n";
                out_file << "@R14" << "\n";
                out_file << "A=M" << "\n";
                out_file << "M=D" << "\n";
            }
            out_file << "// finished popping " + segment + " " + std::to_string(index) << "\n\n";
        }
    }

    void writeLabel(std::string str)
    {
        out_file << "(" + m_file_name + "$" + str + ")" << "\n";
        out_file << "// finished label " + str << "\n\n";
    }

    void writeGoto(std::string str)
    {
        out_file << "@" << m_file_name + '$' + str  << "\n";
        out_file << "0;JMP" << "\n";
        out_file << "//finished goto label " + str << "\n\n";
    }

    void writeIf(std::string str)
    {
        goToNextValueMem(out_file);
        out_file << "D=M" << "\n";
        out_file << "@" << m_file_name + '$' + str << "\n";
        out_file << "D;JNE" << "\n"; 
        out_file << "//finished if goto " + str << "\n\n";
    }

    void writeFunction(std::string name, int n_vars)
    {
        out_file << "(" << name << ")" << "\n";
        for (int i = 0; i < n_vars; i++)
        {
           writePushPop(CommandType::C_PUSH, "constant", 0); 
        }
        out_file << "// finished writing function dec \n\n";
    }

    void writeCall(std::string name, int n_args)
    {
        // how do i know what function I am in?? for return address
        out_file << "@" << m_file_name << "." << "$ret." << "\n";

        out_file << "D=A" << "\n";
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);
        out_file << "@LCL" << "\n";
        out_file << "D=M" << "\n";
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);
        out_file << "@ARG" << "\n";
        out_file << "D=M" << "\n";
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);
        out_file << "@THIS" << "\n";
        out_file << "D=M" << "\n";
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);
        out_file << "@THAT" << "\n";
        out_file << "D=M" << "\n";
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);
        auto decrem = 5 - n_args; 
        out_file << "@SP" << "\n";
        out_file << "D=M" << "\n";
        out_file << "@" << decrem << "\n";
        out_file << "D=D-A" << "\n";
        out_file << "@ARG" << "\n";
        out_file << "M=D" << "\n";
        out_file << "@SP" << "\n";
        out_file << "D=M" << "\n";
        out_file << "@LCL" << "\n";
        out_file << "M=D" << "\n";
        
        // goto  function
        out_file << "@" << name << "\n";
        out_file << "0;JMP" << "\n";

        out_file << "(" + m_file_name << "." << name << "$ret." << ")" << "\n";
        out_file << "// finished calling function " << name << "\n\n";
    }

    void writeReturn()
    {
        // R13 := frame
        // R14 := retAddr

        // put frame in temp
        write_out("@LCL");
        write_out("D=M");
        write_out("@R13");
        write_out("M=D");

        // put retAddr in R14
        write_out("@5");
        write_out("D=A");
        write_out("@R13");
        write_out("A=M-D");
        write_out("D=M");
        write_out("@R14");
        write_out("M=D");

        // reassign ARG
        goToNextValueMem(out_file);
        write_out("D=M");
        write_out("@ARG");
        write_out("A=M");
        write_out("M=D");

        // reassign SP
        write_out("A=A+1");
        write_out("D=A");
        write_out("@SP");
        write_out("M=D");

        // reassign THAT
        write_out("@1");
        write_out("D=A");
        write_out("@R13");
        write_out("A=M-D");
        write_out("D=M");
        write_out("@THAT");
        write_out("M=D");

        // reassign THIS
        write_out("@2");
        write_out("D=A");
        write_out("@R13");
        write_out("A=M-D");
        write_out("D=M");
        write_out("@THIS");
        write_out("M=D");

        // reassign ARG 
        write_out("@3");
        write_out("D=A");
        write_out("@R13");
        write_out("A=M-D");
        write_out("D=M");
        write_out("@ARG");
        write_out("M=D");

        // reassign LCL 
        write_out("@4");
        write_out("D=A");
        write_out("@R13");
        write_out("A=M-D");
        write_out("D=M");
        write_out("@LCL");
        write_out("M=D");

        // go back
        write_out("@R14");
        write_out("A=M");
        write_out("0;JMP");
        write_out("//finished writing function return \n");
    }

    void writeEndLoop()
    {
        out_file << "(END)" << "\n";
        out_file << "@END" << "\n";
        out_file << "0;JMP" << "\n";
    }

    void close()
    {
        return;
    }


private:
    void write_out(std::string line_str)
    {
        out_file << line_str << "\n"; 
    }

    void addSegmentAddressToR14(std::ofstream& out, const std::string& segment, const int index)
    {
           out << "@" << index << "\n";
           out << "D=A" << "\n";
           out << "@" << segment << "\n";
           out << "D=M+D" << "\n";
           out << "@R14" << "\n";
           out << "M=D" << "\n";
    }
    void atTrueVar(std::ofstream& out)
    {
        out_file << "@TRUE_VALUE_" << std::to_string(m_true_count) << "\n";
    }
    void addTrueLabel(std::ofstream& out)
    {
        out_file << "(TRUE_VALUE_" << std::to_string(m_true_count) << ")" << "\n";
    }
    void jumpToExitConditionalVar(std::ofstream& out)
    {
        out_file << "@EXIT_CONDITIONAL_" << std::to_string(m_true_count) << "\n";
        out_file << "0;JMP" << "\n";
    }
    void addExitConditionalLabel(std::ofstream& out)
    {
        out_file << "(EXIT_CONDITIONAL_" << std::to_string(m_true_count) << ")" << "\n";
        m_true_count++;
    }
    void goToNextValueMem(std::ofstream& out)  
    {
        out_file << "@SP" << "\n";
        out_file << "M=M-1" << "\n";
        out_file << "A=M" << "\n";
    }
    void replaceCurrentTopMemWithD(std::ofstream& out)
    {
        out_file << "@SP" << "\n";
        out_file << "A=M" << "\n";
        out_file << "M=D" << "\n";
    }
    void incrementStackPointer(std::ofstream& out)
    {
        out_file << "@SP" << "\n";
        out_file << "M=M+1" << "\n";
    }
    std::string m_file_name;
    std::ofstream out_file;
    std::unordered_map<std::string,std::string> m_segment_map;
    std::unordered_map<std::string, int> m_function_call_map;
    std::unordered_map<int,int> m_static_map;
    uint m_true_count;
};