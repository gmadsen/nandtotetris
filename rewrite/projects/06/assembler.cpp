// main assembler prog

#include "Parser.hpp"
#include "Translator.hpp"
#include <fstream>
#include <fstream>

#include <string>

std::string decToBin16Bit(const std::string& snum)
{
    auto num = std::stoi(snum);
    std::string new_num;
    for (auto i = 0; i < 16; i++)
    {
        if (num % 2 == 0)
        {
            new_num += '0';
        }
        else
        {
            new_num += '1';
        }
        num /= 2;
    }
    std::reverse(std::begin(new_num), std::end(new_num));
    return new_num;
}

int main(int argc, char** argv)
{
   Parser parser(argv[1]); 
   Translator translator;

    std::ofstream out_file;
    out_file.open(parser.fileName() + ".hack");

   while (parser.hasMoreLines())
   {
       parser.advanced();


       if (parser.instructionType() == Type::COMMENT) 
       {
           continue;
       }
       std::cout << "type: " << static_cast<int>(parser.instructionType()) << "\n";
       std::cout << "symbol: " << parser.symbol() << "\n";
       std::cout << "dest: " << parser.dest() << "\n";
       std::cout << "comp: " << parser.comp() << "\n";
       std::cout << "jump: " << parser.jump() << "\n";
       std::cout << "\n" << std::endl;

       if (parser.instructionType() == Type::A_INSTRUCTION)
       {
           out_file << decToBin16Bit(parser.symbol()) << "\n";
           continue;
            
       }
       else if (parser.instructionType() == Type::C_INSTRUCTION)
       {
           std::string l_instr = "111";

           std::cout << "L-instr comp: " << parser.comp() << ", size: " << parser.comp().size() << "\n";
        //    for (auto & letter : parser.comp())
        //    {
        //        std::cout << int(letter) << " "; 
        //    }
        //    std::cout << ", size: " << parser.comp().size() << "\n";
           std::cout << "L-instr dest: " << parser.dest() << ", size: " << parser.dest().size() << "\n";

           std::cout << "L-instr jump: " << parser.jump() << ", size: " << parser.jump().size() << "\n";



           std::cout << "L-instr comp trans: " << translator.comp(parser.comp()) << "\n";
           std::cout << "L-instr dest trans: " << translator.dest(parser.dest()) << "\n";
           std::cout << "L-instr jump trans: " << translator.jump(parser.jump()) << "\n";

           l_instr += translator.comp(parser.comp());
           l_instr += translator.dest(parser.dest());
           l_instr += translator.jump(parser.jump());
           out_file << l_instr << "\n";

           continue;

       }
       else if (parser.instructionType() == Type::L_INSTRUCTION)
       {
           out_file << "xxxxxxxxxxxxxxx" << "\n";
       }
;
   }
   out_file.close();
   return 0;
}