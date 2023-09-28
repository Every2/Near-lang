#include "Scanner.hpp"
#include <cstddef>
#include <optional>


bool Scanner::isAtEnd() {
    return current >= source.length();
}

std::vector<Token> Scanner::scanTokens() {
    std::string empty {""};
    while (!isAtEnd()) {
        start = current;
        scanTokens();
    }

    tokens.push_back(Token(Types::TokenType::EOF, empty, empty , line));
    return tokens;
}

char Scanner::advance() {
    return source.at(current++);
}

void Scanner::addToken(Types::TokenType type) {
    addToken(type);
}

void Scanner::addToken(Types::TokenType type, std::string& literal) {
    std::string text {source.substr(start, current)};
    tokens.push_back(Token(type, text, literal, line));
}

void Scanner::scanToken() {
    char c {advance()};
    switch (c) {
        case '(': addToken(Types::TokenType::LEFT_PAREN); break;
        case ')': addToken(Types::TokenType::RIGHT_PAREN); break;
        case '{': addToken(Types::TokenType::LEFT_BRACE); break;
        case '}': addToken(Types::TokenType::RIGHT_BRACE); break;
        case ',': addToken(Types::TokenType::COMMA); break;
        case '.': addToken(Types::TokenType::DOT); break;
        case '-': addToken(Types::TokenType::MINUS); break;
        case '+': addToken(Types::TokenType::PLUS); break;
        case ';': addToken(Types::TokenType::SEMICOLON); break;
        case '*': addToken(Types::TokenType::STAR); break;
    }
}