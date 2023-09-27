#include <iostream>
#include <string>
#include "errorHandler.hpp"

bool ErrorHandler::hadError {false};

void ErrorHandler::error(int line, std::string message) {
    report(line, "", message);
}

void ErrorHandler::report(int line, std::string where, std::string message) {
    std::cerr << "[line " << line << "] Error" << where << ": " << message;
    hadError = true;
}
