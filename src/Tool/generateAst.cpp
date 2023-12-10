#include <iostream>
#include <string>
int main(int argc, char const *argv[]) {
    if (argc != 1) {
        std::cerr << ("Usage: generate_ast <output directory>");
        std::exit(64);
    }
    std::string outputDir {argv[0]};
}
