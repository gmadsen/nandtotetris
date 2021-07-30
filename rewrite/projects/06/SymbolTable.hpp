// symbol map
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

class SymbolTable
{
public:

    SymbolTable() : m_var_count(16)
    {
        m_symbol_map["R0"] = "0";
        m_symbol_map["R1"] = "1";
        m_symbol_map["R2"] = "2";
        m_symbol_map["R3"] = "3";
        m_symbol_map["R4"] = "4";
        m_symbol_map["R5"] = "5";
        m_symbol_map["R6"] = "6";
        m_symbol_map["R7"] = "7";
        m_symbol_map["R8"] = "8";
        m_symbol_map["R9"] = "9";
        m_symbol_map["R10"] = "10";
        m_symbol_map["R11"] = "11";
        m_symbol_map["R12"] = "12";
        m_symbol_map["R13"] = "13";
        m_symbol_map["R14"] = "14";
        m_symbol_map["R15"] = "15";

        m_symbol_map["SP"] = "0";
        m_symbol_map["LCL"] = "1";
        m_symbol_map["ARG"] = "2";
        m_symbol_map["THIS"] = "3";
        m_symbol_map["THAT"] = "4";

        m_symbol_map["SCREEN"] = "16384";
        m_symbol_map["KBD"] = "24576";

    }
    void addLabel(const std::string& label, int line_count)
    {
        if (m_symbol_map.find(label) != m_symbol_map.end())
        {
            return; 
        } 
        else
        {
            m_symbol_map[label] = std::to_string(line_count);
        }
    }
    void addVariable(const std::string& variable)
    {
        if (m_symbol_map.find(variable) != m_symbol_map.end())
        {
            return; 
        }
        else
        {
            m_symbol_map[variable] = std::to_string(m_var_count);
            //std::cout << "variable: " << variable << " , var_count: " << m_var_count << "\n";
            m_var_count++;
        }
    }
    std::string getSymbol(const std::string& symbol)
    {    
        return m_symbol_map[symbol];
    }

    void printSymbols()
    {
        for (auto& i : m_symbol_map)
        {
            std::cout << "key: " << i.first << " , value: " << i.second << "\n";
        }
        std::cout << "\n\n";
    }
    
private:
int m_var_count;
public:
std::map<std::string, std::string> m_symbol_map;
};