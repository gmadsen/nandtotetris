// tokenizer
#include <unordered_set>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

enum class TokenType: uint
{
    KEYWORD,
    SYMBOL,
    IDENTIFIER,
    INT_CONST,
    STRING_CONST
}; 
enum class KeyWord : uint
{
    CLASS,
    METHOD,
    FUNCTION,
    CONSTRUCTOR,
    INT,
    BOOLEAN,
    CHAR,
    VOID,
    VAR,
    STATIC,
    FIELD,
    LET,
    DO,
    IF,
    ELSE,
    WHILE,
    RETURN,
    TRUE,
    FALSE,
    NULLTYPE,
    THIS
}; 

class Tokenizer
{
public:
    Tokenizer(char* in_file) 
    {
        m_in_file.open(in_file)
        createTokens();

    }
    bool hasMoreTokens()
    {
        return false;
    }
    void advance()
    {
        return;
    }
    TokenType tokenType()
    {
        return TokenType::IDENTIFIER;
    }
    KeyWord keyWord()
    {
        return KeyWord::BOOLEAN;
    } 
    char symbol()
    {
        return 'a';
    }
    std::string identifier()
    {
        return "yo";
    }
    int intVal()
    {
        return 5;
    }
    std::string stringVal()
    {
        return "yp";
    }
private:
    void createTokens()
    {
       typedef std::istreambuf_iterator<char> buf_itr;
       for (buf_itr i(m_in_file), e; i != e; i++)
       {

       }
    }
    std::ifstream m_in_file;
    std::vector<std::string> tokens;

};

namespace syntax
{

const std::unordered_set<std::string>& getKeywords()
{
    static const auto* set = new std::unordered_set<std::string>{
        "class",
        "constructor", 
        "function", 
        "method", 
        "field", 
        "static", 
        "var", 
        "int",
        "char",
        "boolean",
        "void",
        "true",
        "false",
        "null",
        "this",
        "let",
        "do",
        "if",
        "else",
        "while",
        "return"
        };
    return *set;
}

const std::unordered_set<char>& getSymbols()
{
    static const auto* set = new std::unordered_set<char>{
        '{',
        '}',
        '(',
        ')',
        '[',
        ']',
        '.',
        ',',
        ';',
        '+',
        '-',
        '*',
        '/',
        '&',
        '|',
        '<',
        '>',
        '=',
        '~' 
        };
    return *set;
}

}
