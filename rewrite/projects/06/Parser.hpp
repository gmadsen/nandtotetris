// Parser
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <unordered_map>

enum class Type: uint
{
    A_INSTRUCTION = 0,
    C_INSTRUCTION = 1,
    L_INSTRUCTION = 2,
    COMMENT       = 3
};

class Parser
{
public:
    Parser(char* in_file)
    {
        m_in_file.open(in_file);
        auto fn = std::string(in_file);
        auto pos = fn.find('.'); 
        m_file_name = fn.substr(0, pos);
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
        m_symbol = "";
        m_dest = "";
        m_comp = "";
        m_jump = "";
        std::getline(m_in_file, m_curr_line);

        m_curr_line.erase(std::remove_if(m_curr_line.begin(), m_curr_line.end(), isspace), m_curr_line.end());
        // std::cout << "\n\n new advanced \n";
        // std::cout << "size of line: " << m_curr_line.size() << "\n";
        // std::cout << "str length: " << m_curr_line.length() << "\n";
        // std::cout << int(m_curr_line[0]) << "\n";
        // std::cout << m_curr_line << "\n\n";
        bool blank_line = std::find_if_not(m_curr_line.begin(), m_curr_line.end(), isspace) == end(m_curr_line);
        if ( (m_curr_line.find("//") == 0) || blank_line ) 
        {
            m_instruction_type = Type::COMMENT;
            return;
        }
        auto new_end = m_curr_line.find("//") - 1;
        // l instruction process
        if ((m_curr_line.find('(') != std::string::npos) && (m_curr_line.find('(') < new_end))
        {
            m_instruction_type =  Type::L_INSTRUCTION;

            auto l_end = m_curr_line.find(')');
            m_symbol = m_curr_line.substr(1,l_end - 1);
            return;
        }
        // A instruction
        if (m_curr_line.find('@') != std::string::npos)
        {
            m_instruction_type = Type::A_INSTRUCTION;
            m_symbol = m_curr_line.substr(1, new_end - 1);
            return;
        }
        // C instruction
        m_instruction_type =  Type::C_INSTRUCTION;
        auto equal = m_curr_line.find('=');
        equal = (equal < new_end) ? equal : std::string::npos;
        auto jbreak = m_curr_line.find(';');
        jbreak = (jbreak < new_end) ? jbreak : std::string::npos;
        if (equal != std::string::npos)
        {
            m_dest = m_curr_line.substr(0, equal); 
            if (jbreak != std::string::npos)
            {
                m_comp = m_curr_line.substr(equal + 1, jbreak - equal - 1); 
            }
            else
            {
                m_comp = m_curr_line.substr(equal + 1, new_end - equal); 
            }
        }
        else
        {
            m_dest = "";
            if (jbreak != std::string::npos)
            {
                m_comp = m_curr_line.substr(0,jbreak);
            }
            else
            {
               m_comp = m_curr_line.substr(0, new_end);
            }
        }
        if (jbreak != std::string::npos)
        {
            m_jump = m_curr_line.substr(jbreak + 1, new_end - 1);
 
        }
        else
        {
            m_jump = "";
        }
       return;

    }
    
    void reset()
    {
        m_in_file.clear();
        m_in_file.seekg(0);
    }

    Type instructionType()
    {
        return m_instruction_type;
    }

    std::string symbol()
    {
        return m_symbol;
    }

    std::string dest()
    {
        return m_dest;
    }

    std::string comp()
    {
        return m_comp;
    }

    std::string jump()
    {
        return m_jump;
    }
    std::string fileName()
    {
        return m_file_name;
    }

private:
    std::ifstream m_in_file;
    std::string m_file_name;
    std::string m_curr_line;
    Type m_instruction_type;
    std::string m_symbol;
    std::string m_dest;
    std::string m_comp;
    std::string m_jump;
};
