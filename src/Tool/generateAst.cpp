#include <iostream>
#include <string>
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << ("Usage: generate_ast <output directory>");
        std::exit(64);
    }
    std::string outputDir {argc[0]};
}
