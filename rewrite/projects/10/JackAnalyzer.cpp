#include "CompilationEngine.hpp"
#include "Tokenizer.hpp"

class JackAnalyzer
{
public:
    JackAnalyzer(Tokenizer& tokenizer, CompilationEngine& engine) : m_tokenizer(tokenizer), m_engine(engine)
    {

    }

    void analyze()
    {

        while (m_tokenizer.hasMoreTokens())
        {
            m_tokenizer.advance();
            if (m_tokenizer.tokenType() == TokenType::IDENTIFIER) 
            {
                m_engine.compileExpression();
            }
        }
    }

private:
    Tokenizer& m_tokenizer;
    CompilationEngine& m_engine;
};


int main(int argc, char** argv)
{


    Tokenizer tokenizer;
    CompilationEngine engine;
    JackAnalyzer analyzer(tokenizer, engine);
    analyzer.analyze();
    return 0;

}
