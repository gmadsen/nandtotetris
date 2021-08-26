#include "CodeWriter.hpp"
#include <cassert>
#include <experimental/filesystem>
#include <string_view>
#include <algorithm>
namespace fs = std::experimental::filesystem;

static bool endsWith(std::string_view str, std::string_view suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

static bool startsWith(std::string_view str, std::string_view prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}


class VMTranslator
{
public:
    VMTranslator(Parser& parser, CodeWriter& writer) : m_parser(parser), m_writer(writer) 
    {
        m_writer.writeBootStrap();
    }


    void translate()
    {

        while (m_parser.hasMoreLines())
        {
            m_parser.advanced();
            if (m_parser.getCommandType() == CommandType::C_PUSH) 
            {
                m_writer.writePush(m_parser.getArgs()[0], stoi(m_parser.getArgs()[1]));
            }
            if (m_parser.getCommandType() == CommandType::C_POP)
            {
                m_writer.writePop(m_parser.getArgs()[0], stoi(m_parser.getArgs()[1]));
            }
            if (m_parser.getCommandType() == CommandType::C_ARITHMETIC)
            {
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
    const fs::path path(argv[1]); // Constructing the path from a string is possible.
    std::error_code ec; // For using the non-throwing overloads of functions below.
    if (fs::is_directory(path, ec))
    { 
        std::cout << "is a directory \n";
        std::vector<std::string> file_vector;
        fs::directory_entry dir(argv[1]);
        for (auto const & p : fs::directory_iterator(path))
        {
            std::string file_string(p.path());
            if (endsWith(file_string, ".vm") )
            {
                file_vector.push_back(file_string);
            }
        }
        bool append_flag = false;
        for (int i = 0; i < file_vector.size(); i++)
        {
            if (i > 0)
            {
                append_flag = true;
            } 
            auto& file = file_vector[i];
            std::string source_name(*std::prev(path.end()));
            source_name = "/" + source_name;
            Parser parser(file);

            CodeWriter writer(file, argv[1] + source_name, append_flag);
            VMTranslator translator(parser, writer);
            translator.translate();
        }
        // auto init = std::find_if(std::begin(file_vector), std::end(file_vector), [](const std::string& a) {return a.find("Sys.vm") != std::string::npos;});
        // if (init != std::end(file_vector))
        // {
        //     std::iter_swap(std::begin(file_vector), init);
        // }
        // PUTTING sys.init first is not needed, just boot strap in ctor
        // TODO handle all files, now that sys.vm is first to be translated
    }
    if (ec) // Optional handling of possible errors.
    {
        std::cerr << "Error in is_directory: " << ec.message();
    }
    if (fs::is_regular_file(path, ec))
    {
        // Process a regular file.
        std::cout << "is a regular file \n";
        Parser parser(argv[1]); 
        CodeWriter writer(argv[1]);
        VMTranslator translator(parser, writer);
        translator.translate();
    }
    if (ec) // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
    {
        std::cerr << "Error in is_regular_file: " << ec.message();
    }
    return 0;

}