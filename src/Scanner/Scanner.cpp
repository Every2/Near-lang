#include "Scanner.hpp"


bool Scanner::isAtEnd() {
    return current >= source.length();
}

std::vector<Token> Scanner::scanTokens() {
    std::string empty {""};
    while (!isAtEnd()) {
        start = current;
        scanTokens();
    }

    tokens.push_back(Token(Types::TokenType::EOF, empty, empty, line));
    return tokens;
}

char Scanner::advance() {
    return source.at(current++);
}

void Scanner::addToken(Types::TokenType type) {
    addToken(type);
}

void Scanner::addToken(Types::TokenType type, std::any literal) {
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
        case '!':
            addToken(match('=' ) ? Types::TokenType::BANG_EQUAL : Types::TokenType::BANG);
            break;
        case '=':
            addToken(match('=') ? Types::TokenType::EQUAL_EQUAL : Types::TokenType::EQUAL);
            break;
        case '<':
            addToken(match('=') ? Types::TokenType::LESS_EQUAL : Types::TokenType::LESS);
            break;
        case '>':
            addToken(match('=') ? Types::TokenType::GREATER_EQUAL : Types::TokenType::GREATER);
            break;
        case '/':
            if (match('/')) {
                while (peek() != '\n' && !isAtEnd()) advance();
            }
            else {
                addToken(Types::TokenType::SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            break;
        
        case '\n': line++; break;
        case '"': string();
        default: 
            if (isDigit(c)) {
                number();
            }
            else {
                ErrorHandler::error(line, "Unexpected character."); 
                break;
            }
    }
}

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source.at(current) != expected) return false;

    current++;
    return true;
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return source.at(current);
}

void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }

    if (isAtEnd()) {
        ErrorHandler::error(line, "unterminated string");
        return;
    }

    advance();

    std::string value {source.substr(start + 1, current - 1)};
    addToken(Types::TokenType::STRING, value); 
}

bool Scanner::isDigit(char c) {
    return c >= '0' && c <= '9';
}

void Scanner::number() {
    while(isDigit(peek())) advance();

    if (peek() == '.' && isDigit(peekNext())) {
        advance();
        while (isDigit(peek())) advance();
    }

    double teste {std::stod(source.substr(start, current))};
    addToken(Types::TokenType::NUMBER, std::stod(source.substr(start, current)));
}

char Scanner::peekNext() {
    if (current + 1 >= source.length()) return '\0';
    return source.at(current + 1);
}