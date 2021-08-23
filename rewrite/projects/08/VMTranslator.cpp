#include "CodeWriter.hpp"
#include <cassert>


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
            if (m_parser.getCommandType() == CommandType::C_PUSH || m_parser.getCommandType() == CommandType::C_POP)
            {
                assert(m_parser.getArgs().size() == 2);
                m_writer.writePushPop(m_parser.getCommandType(), m_parser.getArgs()[0], stoi(m_parser.getArgs()[1]));
            }
            if (m_parser.getCommandType() == CommandType::C_ARITHMETIC)
            {
                assert(m_parser.getArgs().size() == 1);
                m_writer.writeArithmetic(m_parser.getArgs()[0]);
            }
            if (m_parser.getCommandType() == CommandType::C_LABEL)
            {
                m_writer.writeLabel(m_parser.getArgs()[0]);
            }
            if (m_parser.getCommandType() == CommandType::C_GOTO)
            {
                m_writer.writeGoto(m_parser.getArgs()[0]);
            }
            if (m_parser.getCommandType() == CommandType::C_IF)
            {
                m_writer.writeIf(m_parser.getArgs()[0]);
            }
            if (m_parser.getCommandType() == CommandType::C_CALL)
            {
                m_writer.writeCall(m_parser.getArgs()[0], stoi(m_parser.getArgs()[1]));
            }
            if (m_parser.getCommandType() == CommandType::C_FUNCTION)
            {
                m_writer.writeFunction(m_parser.getArgs()[0], stoi(m_parser.getArgs()[1]));
            }
            if (m_parser.getCommandType() == CommandType::C_RETURN)
            {
                m_writer.writeReturn();
            }
        }
        m_writer.writeEndLoop();
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