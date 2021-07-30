// main assembler prog

#include "Parser.hpp"
#include "Translator.hpp"
#include "SymbolTable.hpp"
#include <fstream>
#include <fstream>

#include <string>


class Assembler
{
public:
    Assembler(Parser& parser, Translator& translator, SymbolTable& symbol_table) : m_parser(parser), m_translator(translator), m_symbol_table(symbol_table)
    {
    }

    std::string decToBin16Bit(const std::string& snum)
    {
        //std::cout << "string in dectobit call: " << snum << "\n";
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
    void populateSymbolTable()
    {
       int line_counter = 0; 
       while(m_parser.hasMoreLines())
       {

            m_parser.advanced();
            //std::cout << "symbol poping \n";
            //printDiag();
 
            if ( (m_parser.instructionType() == Type::L_INSTRUCTION) )
            {
                m_symbol_table.addLabel(m_parser.symbol(), line_counter); 
                continue;
            }
            if (m_parser.instructionType() == Type::A_INSTRUCTION || m_parser.instructionType() == Type::C_INSTRUCTION)
            {
                line_counter++;
            }

        }
        m_parser.reset();
        //m_symbol_table.printSymbols();
    }

    void assemble()
    {
        std::ofstream out_file;
        out_file.open(m_parser.fileName() + ".hack");

        while (m_parser.hasMoreLines())
        {
            m_parser.advanced();
            //std::cout << "assembling \n";
            //printDiag();

            if (m_parser.instructionType() == Type::COMMENT) 
            {
                continue;
            }
            

            if (m_parser.instructionType() == Type::A_INSTRUCTION)
            {
                std::string output ="";
                bool has_only_digits = (m_parser.symbol().find_first_not_of( "0123456789" ) == std::string::npos);
                if (has_only_digits)
                {
                    output = decToBin16Bit(m_parser.symbol()); 
                }
                else
                {
                    m_symbol_table.addVariable(m_parser.symbol());
                    output = decToBin16Bit(m_symbol_table.getSymbol(m_parser.symbol()));
                }
                //std::cout << "symbol: " << m_parser.symbol() << "\n";
                out_file << output << "\n";
                continue;
                 
            }
            else if (m_parser.instructionType() == Type::C_INSTRUCTION)
            {
                std::string l_instr = "111";

                l_instr += m_translator.comp(m_parser.comp());
                l_instr += m_translator.dest(m_parser.dest());
                l_instr += m_translator.jump(m_parser.jump());
                out_file << l_instr << "\n";

                continue;

            }
            else if (m_parser.instructionType() == Type::L_INSTRUCTION)
            {
                //out_file << "xxxxxxxxxxxxxxx" << "\n";
            }
        }
        out_file.close();
    }
    void printDiag()
    {
            std::cout << "type: " << static_cast<int>(m_parser.instructionType()) << "\n";
            std::cout << "symbol: " << m_parser.symbol() << "\n";
            std::cout << "dest: " << m_parser.dest() << "\n";
            std::cout << "comp: " << m_parser.comp() << "\n";
            std::cout << "jump: " << m_parser.jump() << "\n";
            std::cout << "\n" << std::endl;   
            std::cout << "L-instr comp: " << m_parser.comp() << ", size: " << m_parser.comp().size() << "\n";
            std::cout << "L-instr dest: " << m_parser.dest() << ", size: " << m_parser.dest().size() << "\n";
            std::cout << "L-instr jump: " << m_parser.jump() << ", size: " << m_parser.jump().size() << "\n";
            std::cout << "L-instr comp trans: " << m_translator.comp(m_parser.comp()) << "\n";
            std::cout << "L-instr dest trans: " << m_translator.dest(m_parser.dest()) << "\n";
            std::cout << "L-instr jump trans: " << m_translator.jump(m_parser.jump()) << "\n";
            std::cout << "\n";
    }

    Parser& m_parser;
    Translator& m_translator;
    SymbolTable& m_symbol_table;
    
};

int main(int argc, char** argv)
{
   Parser parser(argv[1]); 
   Translator translator;
   SymbolTable symbol_table;
   Assembler assembler(parser, translator, symbol_table);  
   assembler.populateSymbolTable();
   assembler.assemble();


  
   return 0;
}