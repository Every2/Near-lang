#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <algorithm>

class GenerateAst {


private:
    static void defineAst(std::string& outputDir, 
    std::string& baseName, std::vector<std::string>& types) {
        try  {

            std::string path {outputDir + "/" + baseName + ".cpp"};
            std::ofstream writer(path);

            if (writer.is_open()) {
                writer << "#include <iostream>" << '\n';
                writer << '\n';
                writer << "#include <vector>" << '\n';
                writer << '\n';
                writer <<  "Class " << baseName << " {";
                writer << '\n';
                writer << "public: " << '\n';
                writer << " virtual " << '~' << baseName << "()" << " =" << " default" << '\n';
                writer << "}";
                writer.close();
            }

            for (std::string type : types) {

            }

            throw std::runtime_error("IoExpection");

        } catch (const std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    };
};