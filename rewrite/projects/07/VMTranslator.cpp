#include "CodeWriter.hpp"


class VMTranslator
{
public:
    VMTranslator(Parser& parser, CodeWriter& writer) : m_parser(parser), m_writer(writer) 
    {

    }


    void translate()
    {

        while (m_parser.hasMoreLines())
        {
            m_parser.advanced();
            if (m_parser.getCommandType == CommandType::C_PUSH || m_parser.getCommandType == CommandType::C_POP)
            {
                m_writer.writePushPop(m_parser.getArg1);
            }
            if (m_parser.getCommandType == CommandType::C_ARITHMETIC)
            {
                m_writer.writeArithmetic(m_parser.getCommandType(), m_parser.getArg1(), m_parser.getArg2);
            }
            //std::cout << static_cast<uint>(m_parser.getCommandType()) << "\n";
        }
    }
private:
    Parser& m_parser;
    CodeWriter& m_writer; 
};

int main(int argc, char** argv)
{
    Parser parser(argv[1]); 
    CodeWriter writer(argv[1]);
    VMTranslator translator(parser, writer);
    translator.translate();

    return 0;

}