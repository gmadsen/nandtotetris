#include "Parser.hpp"

#include <string>
#include <iostream>

class CodeWriter
{
public:
    CodeWriter(std::string name) 
    {
        auto pos = name.find('.');
        auto file_name = name.substr(0, pos) + ".asm";
        out_file.open(file_name);
    }

    ~CodeWriter()
    {
        out_file.close();
    }

    void writeArithmetic(std::string command)
    {

        return;
    }

    void writePushPop(CommandType command, std::string segment, int index)
    {
        return;
    }

    void writeEndLoop();
    {
        return;
    }

    void close()
    {
        return;
    }


private:
    std::ofstream out_file;
};