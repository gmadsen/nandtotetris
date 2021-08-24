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

        auto dot_pos = name.rfind('.');
        auto slash_pos = name.rfind('/');
        m_file_name = name.substr(slash_pos + 1, dot_pos - slash_pos - 1); 
        m_current_function_scope = m_file_name + ".main";
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
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("M=M+D");
            incrementStackPointer(out_file);
            writeOut( "// finished adding \n"); 
        }
        else if (command == "sub")
        {
            goToNextValueMem(out_file);
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("M=M-D");
            incrementStackPointer(out_file);
            writeOut( "// finished substraction \n");  
 
        }
        else if (command == "neg")
        {
            goToNextValueMem(out_file);
            writeOut("M=-M");
            incrementStackPointer(out_file);
            writeOut("//finished neg \n");
        }
        else if (command == "eq")
        {
            goToNextValueMem(out_file);
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("D=M-D");
            atTrueVar(out_file);
            writeOut("D;JEQ");

            writeOut("//entering false branch");
            writeOut("@0");
            writeOut("D=A");
            replaceCurrentTopMemWithD(out_file);
            jumpToExitConditionalVar(out_file);

            writeOut("//entering true branch");
            addTrueLabel(out_file);
            writeOut("@0");
            writeOut("D=!A");
            replaceCurrentTopMemWithD(out_file);
            addExitConditionalLabel(out_file);

            incrementStackPointer(out_file);
            writeOut("//finished eq \n");
        }
        else if (command == "gt")
        {
            goToNextValueMem(out_file);
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("D=M-D");
            atTrueVar(out_file);
            writeOut("D;JGT");

            writeOut("//entering false branch");
            writeOut("@0");
            writeOut("D=A");
            replaceCurrentTopMemWithD(out_file);
            jumpToExitConditionalVar(out_file);

            writeOut("//entering true branch");
            addTrueLabel(out_file);
            writeOut("@0");
            writeOut("D=!A");
            replaceCurrentTopMemWithD(out_file);
            addExitConditionalLabel(out_file);
            incrementStackPointer(out_file);
            writeOut("//finished gt \n");

        }
        else if (command == "lt")
        {
            goToNextValueMem(out_file);
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("D=M-D");
            atTrueVar(out_file);
            writeOut("D;JLT");

            writeOut("//entering false branch");
            writeOut("@0");
            writeOut("D=A");
            replaceCurrentTopMemWithD(out_file);
            jumpToExitConditionalVar(out_file);

            writeOut("//entering true branch");
            addTrueLabel(out_file);
            writeOut("@0");
            writeOut("D=!A");
            replaceCurrentTopMemWithD(out_file);

            addExitConditionalLabel(out_file);
            incrementStackPointer(out_file);
            writeOut("//finished lt \n");
        }
        else if (command == "and")
        {
            goToNextValueMem(out_file);
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("M=M&D");

            incrementStackPointer(out_file);
            writeOut("//finished and \n");
        }
        else if (command == "or")
        {
            goToNextValueMem(out_file);
            writeOut("D=M");
            goToNextValueMem(out_file);
            writeOut("M=M|D");
            incrementStackPointer(out_file);
            writeOut("//finished or \n");
 
        }
        else if (command == "not")
        {
            goToNextValueMem(out_file);
            writeOut("M=!M");
            incrementStackPointer(out_file);
            writeOut("//finished not \n");
 
        }

    }
    void writePop(std::string segment, int index)
    {
        std::string asm_segment;
        goToNextValueMem(out_file);
        writeOut("D=M");
        if (segment == "pointer")
        {
            asm_segment = (index == 0) ? "THIS" : "THAT";
            writeOut("@" + asm_segment);
            writeOut("M=D");
        }
        else if (segment == "static")
        {
            auto var_idx = m_static_map.find(index);
            if (var_idx == m_static_map.end())
            {
                auto cur_size = m_static_map.size();
                m_static_map.insert({index, cur_size});  ///TODO this probably isn't needed
            }
            writeOut("@" + m_file_name + "." + std::to_string(m_static_map[index]));
            writeOut("M=D");
        }
        else if (segment == "temp")
        {
            int base = 5;
            int temp_address = base + index;
            writeOut("@" + std::to_string(temp_address));
            writeOut("M=D");
        }
        else
        {
            writeOut("@R13");
            writeOut("M=D");
            asm_segment = m_segment_map[segment];
            addSegmentAddressToR14(out_file, asm_segment, index);
            writeOut("@R13");
            writeOut("D=M");
            writeOut("@R14");
            writeOut("A=M");
            writeOut("M=D");
        }
        writeOut("// finished popping " + segment + " " + std::to_string(index) +  "\n");
    }
    void writePush(std::string segment, int index)
    {
        if (segment == "constant") 
        {
            writeOut("@" + std::to_string(index));
            writeOut("D=A");
            replaceCurrentTopMemWithD(out_file);
            incrementStackPointer(out_file);
 
        }
        else if (segment == "static")
        {
            writeOut("@" + m_file_name + "." + std::to_string(m_static_map[index]));
            writeOut("D=M");
            replaceCurrentTopMemWithD(out_file);
            incrementStackPointer(out_file);
        }
        else if (segment == "temp")
        {
            int base = 5;
            int temp_address = base + index;
            writeOut("@" + std::to_string(temp_address));
            writeOut("D=M");
            replaceCurrentTopMemWithD(out_file);
            incrementStackPointer(out_file);
        }
        else
        {
            std::string asm_segment;
            if (segment == "pointer")
            {
                asm_segment = (index == 0) ? "THIS" : "THAT";
                writeOut("@" + asm_segment);
                writeOut("D=M");

            }
            else
            {
                asm_segment = m_segment_map[segment];
                addSegmentAddressToR14(out_file, asm_segment, index); 
                writeOut("A=D");
                writeOut("D=M");
            }
            replaceCurrentTopMemWithD(out_file);
            incrementStackPointer(out_file);
        }
        writeOut("// finished pushing: " + segment + " " + std::to_string(index) + "\n"); 
    }

    void writeLabel(std::string str)
    {
        writeOut("(" + m_current_function_scope + "$" + str + ")");
        writeOut("// finished label " + str + "\n");
    }

    void writeGoto(std::string str)
    {
        writeOut("@" + m_current_function_scope + '$' + str);
        writeOut("0;JMP");
        writeOut("//finished goto label " + m_current_function_scope + "$" + str + "\n");
    }

    void writeIf(std::string str)
    {
        goToNextValueMem(out_file);
        writeOut("D=M");
        writeOut("@" + m_current_function_scope + '$' + str);
        writeOut("D;JNE");
        writeOut("//finished if goto " + m_current_function_scope + "$" + str + "\n");
    }

    void writeFunction(std::string name, int n_vars)
    {
        writeOut("(" + name + ")");
        for (int i = 0; i < n_vars; i++)
        {
           writePush("constant", 0); 
        }
        m_current_function_scope = name;
        m_function_call_map[name] = 0;
        writeOut("// finished writing function dec \n");
    }

    void writeCall(std::string name, int n_args)
    {
        auto return_label = m_current_function_scope + "$ret" + std::to_string(m_function_call_map[m_current_function_scope]);
        writeOut("@" + return_label);
        writeOut("D=A");
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);

        writeOut("@LCL");
        writeOut("D=M");
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);

        writeOut("@ARG");
        writeOut("D=M");
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);

        writeOut("@THIS");
        writeOut("D=M");
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);

        writeOut("@THAT");
        writeOut("D=M");
        replaceCurrentTopMemWithD(out_file);
        incrementStackPointer(out_file);

        auto decrem = 5 + n_args; 
        writeOut("@SP");
        writeOut("D=M");
        writeOut("@" + std::to_string(decrem));
        writeOut("D=D-A"); 
        writeOut("@ARG");
        writeOut("M=D");
        writeOut("@SP");
        writeOut("D=M");
        writeOut("@LCL");
        writeOut("M=D");
        
        // goto  function
        writeOut("@" + name);
        writeOut("0;JMP");
        writeOut("// jump to function " + name + "\n");

        writeOut("(" + return_label +  ")");
        m_function_call_map[m_current_function_scope] += 1;
        writeOut("// finished calling function " + name + "\n");
    }

    void writeReturn()
    {
        // R13 := frame
        // R14 := retAddr

        // put frame in temp
        writeOut("@LCL");
        writeOut("D=M");
        writeOut("@R13");
        writeOut("M=D");

        // put retAddr in R14
        writeOut("@5");
        writeOut("D=A");
        writeOut("@R13");
        writeOut("A=M-D");
        writeOut("D=M");
        writeOut("@R14");
        writeOut("M=D");

        // reassign ARG
        goToNextValueMem(out_file);
        writeOut("D=M");
        writeOut("@ARG");
        writeOut("A=M");
        writeOut("M=D");

        // reassign SP
        writeOut("D=A+1");
        writeOut("@SP");
        writeOut("M=D");

        // reassign THAT
        writeOut("@1");
        writeOut("D=A");
        writeOut("@R13");
        writeOut("A=M-D");
        writeOut("D=M");
        writeOut("@THAT");
        writeOut("M=D");

        // reassign THIS
        writeOut("@2");
        writeOut("D=A");
        writeOut("@R13");
        writeOut("A=M-D");
        writeOut("D=M");
        writeOut("@THIS");
        writeOut("M=D");

        // reassign ARG 
        writeOut("@3");
        writeOut("D=A");
        writeOut("@R13");
        writeOut("A=M-D");
        writeOut("D=M");
        writeOut("@ARG");
        writeOut("M=D");

        // reassign LCL 
        writeOut("@4");
        writeOut("D=A");
        writeOut("@R13");
        writeOut("A=M-D");
        writeOut("D=M");
        writeOut("@LCL");
        writeOut("M=D");

        // go back
        writeOut("@R14");
        writeOut("A=M");
        writeOut("0;JMP");
        writeOut("//finished writing function return " + m_current_function_scope + "\n");
    }

    void writeEndLoop()
    {
        writeOut("(END)");
        writeOut("@END");
        writeOut("0;JMP");
    }

    void close()
    {
        return;
    }
private:
    void addSegmentAddressToR14(std::ofstream& out, const std::string& segment, const int index)
    {
           writeOut("@" + std::to_string(index));
           writeOut("D=A");
           writeOut("@" + segment);
           writeOut("D=M+D");
           writeOut("@R14");
           writeOut("M=D");
    }
    void atTrueVar(std::ofstream& out)
    {
        writeOut("@" + m_file_name + "_TRUE_VALUE_" + std::to_string(m_true_count));
    }
    void addTrueLabel(std::ofstream& out)
    {
        writeOut("(" + m_file_name + "_TRUE_VALUE_" + std::to_string(m_true_count) + ")");
    }
    void jumpToExitConditionalVar(std::ofstream& out)
    {
        writeOut("@" + m_file_name + "_EXIT_CONDITIONAL_" + std::to_string(m_true_count));
        writeOut("0;JMP");
    }
    void addExitConditionalLabel(std::ofstream& out)
    {
        writeOut("(" + m_file_name + "_EXIT_CONDITIONAL_" + std::to_string(m_true_count) + ")");
        m_true_count++;
    }
    void goToNextValueMem(std::ofstream& out)  
    {
        writeOut("@SP");
        writeOut("M=M-1");
        writeOut("A=M");
    }
    void replaceCurrentTopMemWithD(std::ofstream& out)
    {
        writeOut("@SP");
        writeOut("A=M");
        writeOut("M=D");
    }
    void incrementStackPointer(std::ofstream& out)
    {
        writeOut("@SP");
        writeOut("M=M+1");
        writeOut("//increment SP");
    }
    void writeOut(std::string line_str)
    {
        out_file << line_str << "\n"; 
    }

    std::string m_file_name;
    std::ofstream out_file;
    std::unordered_map<std::string,std::string> m_segment_map;
    std::unordered_map<std::string, int> m_function_call_map;
    std::unordered_map<int,int> m_static_map;
    uint m_true_count;
    std::string m_current_function_scope;
};