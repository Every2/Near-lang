#include <ostream>
#include <string>
#include <any>
#include "map"

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
    
    Token(Types::TokenType type, std::string& lexeme, std::any literal, int line): type(type), lexeme(lexeme), line(line), literal(literal) {}
    

    static std::map<Types::TokenType, std::string> stringTypes;
    const Types::TokenType type;
    const std::string lexeme;
    const std::any literal;
    const int line;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};

