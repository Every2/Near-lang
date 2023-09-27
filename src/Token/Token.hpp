#include "TokenType.hpp"
#include <string>

class Token {

public:
    
    Token(TokenType type, std::string& lexeme, std::string& literal, int line): type(type), lexeme(lexeme), line(line), literal(literal) {}
    
    const TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;

};