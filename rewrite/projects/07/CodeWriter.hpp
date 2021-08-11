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

        auto pos = name.rfind('.');
        auto file_name = name.substr(0, pos) + ".asm";
        out_file.open(file_name);
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
            else
            {
                auto asm_segment = m_segment_map[segment];
                addSegmentAddressToR14(out_file, asm_segment, index);
                out_file << "A=D" << "\n";
                out_file << "D=M" << "\n";
                replaceCurrentTopMemWithD(out_file);
                incrementStackPointer(out_file);
            }
           out_file << "// finished pushing: " << segment << " " << std::to_string(index) << "\n\n"; 

        }
        else if (command == CommandType::C_POP)
        {
            goToNextValueMem(out_file);
            out_file << "D=M" << "\n";
            out_file << "@R13" << "\n";
            out_file << "M=D" << "\n";

            auto asm_segment = m_segment_map[segment];
            addSegmentAddressToR14(out_file, asm_segment, index);

            out_file << "@R13" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@R14" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";
        }
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
    std::ofstream out_file;
    std::unordered_map<std::string,std::string> m_segment_map;
    uint m_true_count;
};