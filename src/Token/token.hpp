#include <string>

namespace Types {
    #undef NULL
    #undef EOF
    enum class TokenType {
        //Single character tokens.
        LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
        COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

        //One or Two character tokens.
        BANG, BANG_EQUAL,
        EQUAL, EQUAL_EQUAL,
        GREATER, GREATER_EQUAL,
        LESS, LESS_EQUAL,

        //Literals
        IDENTIFIER, STRING, NUMBER,

        //Keywords
        AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NULL, OR, 
        PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

        EOF
    };
}

class Token {

public:
    
    Token(Types::TokenType type, std::string& lexeme, std::string& literal, int line): type(type), lexeme(lexeme), line(line), literal(literal) {}
    
    const Types::TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;

};