#include <string>
#include <vector>
#include <any>
#include <map>
#include "../Token/token.hpp"
#include "../Error/errorHandler.hpp"


class Scanner {

public:
    Scanner(const std::string& source) : source(source) {}
    std::vector<Token> scanTokens();
    
private:
    int start {0};
    int current {0};
    int line {1};
    const std::string source;
    std::vector<Token> tokens;
    bool isAtEnd();
    void scanToken();
    char advance();
    void addToken(Types::TokenType type);
    void addToken(Types::TokenType type, std::any literal);
    bool match(char expected);
    char peek();
    void string();
    bool isDigit(char c);
    void number();
    char peekNext();
    void identifier();
    bool isAlpha(char c);
    bool isAlphaNumeric(char c);
    const static std::map<std::string, Types::TokenType> keywords;
};