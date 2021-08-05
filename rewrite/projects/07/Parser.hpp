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
        //std::cout << "eof ? : " << m_in_file.eof() << "\n";
        return !m_in_file.eof();
    }

    void advanced()
    {
        m_command_type = CommandType::COMMENT;

        std::getline(m_in_file, m_curr_line);


        std::stringstream s(m_curr_line);
        std::string word;
        //int count = 0;
        while (s >> word)
        {
            //std::cout << "count: " << count << " word: " << word << "\n";
            //count++;
            if (word.find("//") != std::string::npos)
            {
                return;
            }
           
            if (word == "push")
            {
                m_command_type =  CommandType::C_PUSH;
                continue;
            }
            if (word == "pop")
            {
                m_command_type =  CommandType::C_POP;
                continue;
            }
            if (word == "add" || word == "sub" || word == "neg")
            {
                m_command_type = CommandType::C_ARITHMETIC;
                m_arguments.push_back(word);
                continue;
            }
            m_arguments.push_back(word);
        }
        return;

    }
    
    void reset()
    {
        m_in_file.clear();
        m_in_file.seekg(0);
    }

    CommandType getCommandType()
    {
        return m_command_type;
    }

    std::string getArg1()
    {
        return m_arguments[0];
    }

    int getArg2()
    {
        return stoi(m_arguments[1]);
    }

private:
    std::ifstream m_in_file;
    std::string m_curr_line;
    CommandType m_command_type;
    std::vector<std::string> m_arguments;
};
