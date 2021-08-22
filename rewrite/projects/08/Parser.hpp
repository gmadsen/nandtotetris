// Parser
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>

enum class CommandType: uint
{
    C_ARITHMETIC = 0,
    C_PUSH       = 1,
    C_POP        = 2,
    C_LABEL      = 3,
    C_GOTO       = 4,
    C_IF         = 5,
    C_FUNCTION   = 6,
    C_RETURN     = 7,
    C_CALL       = 8,
    COMMENT      = 9
};

class Parser
{
public:
    Parser(char* in_file)
    {
        m_in_file.open(in_file);
        m_arguments.reserve(2);
    }
    ~Parser()
    {
        m_in_file.close();
    }

    bool hasMoreLines()
    {
        return !m_in_file.eof();
    }

    void advanced()
    {
        m_arguments.clear();
        m_command_type = CommandType::COMMENT;

        std::getline(m_in_file, m_curr_line);


        std::stringstream s(m_curr_line);
        std::string word;
        while (s >> word)
        {
            if (word.find("//") != std::string::npos)
            {
                return;
            }
           
            else if (word == "push")
            {
                m_command_type =  CommandType::C_PUSH;
                continue;
            }
            else if (word == "pop")
            {
                m_command_type =  CommandType::C_POP;
                continue;
            }
            else if (word == "label")
            {
                m_command_type = CommandType::C_LABEL;
                continue;
            }
            else if (word == "goto")
            {
                m_command_type = CommandType::C_GOTO;
                continue;
            }
            else if (word == "if-goto")
            {
                m_command_type = CommandType::C_IF;
                continue;
            }
            else if (word == "add" || word == "sub" || word == "neg" || word == "eq" || word == "gt" || word == "lt" || word == "and" || word == "or" || word == "not")
            {
                m_command_type = CommandType::C_ARITHMETIC;
                m_arguments.push_back(word);
                return;
            }
            else
            {
                m_arguments.push_back(word);
            }
            
        }
        return;

    }
    
    void reset()
    {
        m_in_file.clear();
        m_in_file.seekg(0);
    }

    const CommandType getCommandType()
    {
        return m_command_type;
    }

    const std::vector<std::string>& getArgs()
    {
        return m_arguments;
    }

private:
    std::ifstream m_in_file;
    std::string m_curr_line;
    CommandType m_command_type;
    std::vector<std::string> m_arguments;
};
