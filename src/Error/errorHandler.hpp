#include <string>
class ErrorHandler {
    
public:
    static bool hadError;
    static void error(int line, std::string message);
    static void report(int line, std::string where, std::string message);
};