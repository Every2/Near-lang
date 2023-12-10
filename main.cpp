#include <iostream>
#include "src/Stream/filestream.hpp"
#include "src/Error/errorHandler.hpp"

int main(int argc, char* argv[]) {
    Stream file;
    if (argc > 2) {
        std::cout << "Usage: Near[script]";
        if(ErrorHandler::hadError) std::exit(64);
    }
    else if (argc == 2) {
       file.runFile(argv[1]);
    }
    else {
      file.runPrompt();
    }
}