#include <string>
class Stream {

public:
    void run(std::string& source);
    void runFile(const std::string& path);
    void runPrompt();
};