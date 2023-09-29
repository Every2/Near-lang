#include "token.hpp"
#include <any>
#include <string>
#include <iostream>

std::string Token::toString() const {
    const std::map<Types::TokenType, std::string>stringTypes {
    {Types::TokenType::LEFT_PAREN, "LEFT_PAREN"},
    {Types::TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
    {Types::TokenType::LEFT_BRACE, "LEFT_BRACE"},
    {Types::TokenType::RIGHT_BRACE, "Right_BRACE"},
    {Types::TokenType::COMMA, "COMMA"},
    {Types::TokenType::DOT, "DOT"},
    {Types::TokenType::MINUS, "MINUS"},
    {Types::TokenType::PLUS, "PLUS"},
    {Types::TokenType::SEMICOLON, "SEMICOLON"},
    {Types::TokenType::SLASH, "SLASH"},
    {Types::TokenType::STAR, "STAR"},
    {Types::TokenType::BANG, "BANG"},
    {Types::TokenType::BANG_EQUAL, "BANG_EQUAL"},
    {Types::TokenType::EQUAL, "EQUAL"},
    {Types::TokenType::BANG_EQUAL, "BANG_EQUAL"},
    {Types::TokenType::GREATER, "GREATER"},
    {Types::TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
    {Types::TokenType::LESS, "LESS"},
    {Types::TokenType::LESS_EQUAL, "LESS_EQUAL"},
    {Types::TokenType::IDENTIFIER, "IDENTIFIER"},
    {Types::TokenType::STRING, "STRING"},
    {Types::TokenType::NUMBER, "NUMBER"},
    {Types::TokenType::AND, "AND"},
    {Types::TokenType::CLASS, "CLASS"},
    {Types::TokenType::ELSE, "ELSE"},
    {Types::TokenType::FALSE, "FALSE"},
    {Types::TokenType::FUN, "FUN"},
    {Types::TokenType::FOR, "FOR"},
    {Types::TokenType::IF, "IF"},
    {Types::TokenType::NULL, "NULL"},
    {Types::TokenType::OR, "OR"},
    {Types::TokenType::PRINT, "PRINT"},
    {Types::TokenType::RETURN, "RETURN"},
    {Types::TokenType::SUPER, "SUPER"},
    {Types::TokenType::THIS, "THIS"},
    {Types::TokenType::TRUE, "TRUE"},
    {Types::TokenType::VAR, "VAR"},
    {Types::TokenType::WHILE, "WHILE"},
    {Types::TokenType::EOF, "EOF"}
    };

    auto tryFindString {stringTypes.find(type)};
    if (tryFindString != stringTypes.end()) {
        return tryFindString->second + " " + lexeme +  " " + "" + std::to_string(line);
    }
    else {
        return "UNKNOWN " + lexeme + "" + "" + " " + std::to_string(line);
    }
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << token.toString();
    return os;
}