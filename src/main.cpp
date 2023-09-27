#include <iostream>
#include "Stream/filestream.hpp"
#include "Error/errorHandler.hpp"

int main(int argc, char* argv[]) {
    Stream file;
    if (argc > 2) {
        std::cout << "Usage: jlox[script]";
        if(ErrorHandler::hadError) std::exit(64);
    }
    else if (argc == 2) {
       file.runFile(argv[0]);
    }
    else {
       file.runPrompt();
    }
}