#include <string>
class ErrorHandler {
    
public:
    static bool hadError;
    void error(int line, std::string message);
    void report(int line, std::string where, std::string message);
};