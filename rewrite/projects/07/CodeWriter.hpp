#include "Parser.hpp"

#include <string>
#include <iostream>

class CodeWriter
{
public:
    CodeWriter(std::string name) 
    {
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
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=M+D" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << " // finished adding \n" << std::endl; 
        }
        else if (command == "sub")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=M+D" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << " // finished substraction \n" << std::endl; 
 
        }
        else if (command == "neg")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=-M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << "\n";
            out_file << "\n";
        }
        else if (command == "eq")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M-D" << "\n";
            out_file << "@TRUE_VALUE" << "\n";
            out_file << "D;JEQ" << "\n";
            // false code
            out_file << "@0" << "\n";
            out_file << "D=A" << "\n";
            out_file << "@SP" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";
            // true code
            out_file << "(TRUE_VALUE)" << "\n";
            out_file << "@0" << "\n";
            out_file << "D=!A" << "\n";
            out_file << "@SP" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";

            // continue
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << "\n";

            out_file << "\n";
        }
        else if (command == "gt")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M-D" << "\n";
            out_file << "@TRUE_VALUE" << "\n";
            out_file << "D;JGT" << "\n";
            // false code
            out_file << "@0" << "\n";
            out_file << "D=A" << "\n";
            out_file << "@SP" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";
            // true code
            out_file << "(TRUE_VALUE)" << "\n";
            out_file << "@0" << "\n";
            out_file << "D=!A" << "\n";
            out_file << "@SP" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";

            // continue
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << "\n";

            out_file << "\n";

        }
        else if (command == "lt")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M-D" << "\n";
            out_file << "@TRUE_VALUE" << "\n";
            out_file << "D;JGT" << "\n";
            // false code
            out_file << "@0" << "\n";
            out_file << "D=A" << "\n";
            out_file << "@SP" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";
            // true code
            out_file << "(TRUE_VALUE)" << "\n";
            out_file << "@0" << "\n";
            out_file << "D=!A" << "\n";
            out_file << "@SP" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=D" << "\n";

            // continue
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << "\n";
            out_file << "\n";
        }
        else if (command == "and")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=M&D" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << " // finished AND \n" << std::endl; 
        }
        else if (command == "or")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "D=M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=M|D" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << " // finished AND \n" << std::endl; 
 
        }
        else if (command == "not")
        {
            out_file << "@SP" << "\n";
            out_file << "M=M-1" << "\n";
            out_file << "A=M" << "\n";
            out_file << "M=!M" << "\n";
            out_file << "@SP" << "\n";
            out_file << "M=M+1" << "\n";
            out_file << "\n";
 
        }

    }

    void writePushPop(CommandType command, std::string segment, int index)
    {
       if (command == CommandType::C_PUSH) 
       {
           out_file << "@" << std::to_string(index) << "\n";
           out_file << "D=A" << "\n"; 
           out_file << "@SP" << "\n"; 
           out_file << "A=M" << "\n"; 
           out_file << "M=D" << "\n"; 
           out_file << "@SP" << "\n"; 
           out_file << "M=M+1" << "  // finished pushing: " << segment << " " << std::to_string(index) << "\n" << std::endl; 

       }
       else if (command == CommandType::C_POP)
       {
           return;
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
    void enterNextLevelOfStack()
    {
        return;
    }
    std::ofstream out_file;
};