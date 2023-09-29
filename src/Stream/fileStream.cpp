#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "filestream.hpp"
#include "../Scanner/Scanner.hpp"

void Stream::run(std::string& source) {
    Scanner scanner {source};
    std::vector<Token> tokens {scanner.scanTokens()};

    for (Token token : tokens) {
        std::cout << token << '\n';
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
        std::string convertBuffer {buffer.str()};
        run(convertBuffer);
        ErrorHandler::hadError = false;
    }
    catch (const std::exception& e){
        std::cerr << "Error " << e.what() << '\n';
    }
}

void Stream::runPrompt() {
    while (true) {
        std::cout << ">  ";
        std::string line;
        if (!getline(std::cin, line)) {
            break;
        }
        run(line);
    }
}