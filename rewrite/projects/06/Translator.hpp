// translator 
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>


class Translator
{
public:
    // static constexpr auto dest_0 = "null";
    // static constexpr auto dest_1 = "M";
    // static constexpr auto dest_2 = "D";
    // static constexpr auto dest_3 = "DM";
    // static constexpr auto dest_4 = "A";
    // static constexpr auto dest_5 = "AM";
    // static constexpr auto dest_6 = "AD";
    // static constexpr auto dest_7 = "ADM";

    Translator()
    {
        // dest map
        m_dest_map[""]      = "000";
        m_dest_map["M"]     = "001";
        m_dest_map["D"]     = "010";
        m_dest_map["DM"]    = "011";
        m_dest_map["A"]     = "100";
        m_dest_map["AM"]    = "101";
        m_dest_map["AD"]    = "110";
        m_dest_map["ADM"]   = "111";

        // comp map
        m_comp_map["0"] = "0101010";
        m_comp_map["1"] = "0111111";
        m_comp_map["-1"] = "0111010";
        m_comp_map["D"] = "0001100";

        m_comp_map["A"] = "0110000";
        m_comp_map["M"] = "1110000";

        m_comp_map["!D"] = "0001101";

        m_comp_map["!A"] = "0110001";
        m_comp_map["!M"] = "1110001";

        m_comp_map["-D"] = "0001111";

        m_comp_map["-A"] = "0110011";
        m_comp_map["-M"] = "1110011";

        m_comp_map["D+1"] = "0011111";
        
        m_comp_map["A+1"] = "0110111";
        m_comp_map["M+1"] = "1110111";

        m_comp_map["D-1"] = "0001110";

        m_comp_map["A-1"] = "0110010";
        m_comp_map["M-1"] = "1110010";

        m_comp_map["D+A"] = "0000010";
        m_comp_map["D+M"] = "1000010";

        m_comp_map["D-A"] = "0010011";
        m_comp_map["D-M"] = "1010011";

        m_comp_map["A-D"] = "0000111";
        m_comp_map["M-D"] = "1000111";

        m_comp_map["D&A"] = "0000000";
        m_comp_map["D&M"] = "1000000";

        m_comp_map["D|A"] = "0010101";
        m_comp_map["D|M"] = "1010101";

        // jump map
        m_jump_map[""]    = "000";
        m_jump_map["JGT"] = "001";
        m_jump_map["JEQ"] = "010";
        m_jump_map["JGE"] = "011";
        m_jump_map["JLT"] = "100";
        m_jump_map["JNE"] = "101";
        m_jump_map["JLE"] = "110";
        m_jump_map["JMP"] = "111";
    }

    std::unordered_map<std::string, std::string> m_dest_map;
    std::unordered_map<std::string, std::string> m_comp_map;
    std::unordered_map<std::string, std::string> m_jump_map;

    std::string dest(const std::string& dest)
    {
        if (m_dest_map.find(dest) != m_dest_map.end())
        {
            return m_dest_map[dest];
        }
        else
        {
            return "000";
        }
    }

    std::string comp(const std::string& comp)
    {
        if (m_comp_map.find(comp) != m_comp_map.end())
        {
            return m_comp_map[comp];
        }
        else
        {
            return "badboy";
        }
    }

    std::string jump(const std::string& jump)
    {
        if (m_jump_map.find(jump) != m_jump_map.end())
        {
            return m_jump_map[jump];
        }
        else
        {
            return "000";
        }
    }
}; 
