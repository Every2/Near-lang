#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../Type/tokenType.hpp"
#include "filestream.hpp"
#include "../Error/errorHandler.hpp"

void Stream::run(std::string& source) {
    Scanner scanner {new Scanner(source)};
    std::vector<Token> tokens{source};

    for (Token token: tokens) {
        std::cout << token;
    }
}

void Stream::runFile(const std::string& path) {
    try {
        std::ifstream file(path);
        if (!file.is_open()) {
            throw std::runtime_error("Error can not open file " + path);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        run(buffer.str());
        ErrorHandler::hadError = false;
    }
    catch (const std::exception& e){
        std::cerr << "Error " << e.what() << '\n';
    }
}

void Stream::runPrompt() {
    std::string line;
    while (true) {
        if (!std::getline(std::cin, line) || line.empty()) {
            break;
        }
        run(line);
    }
}