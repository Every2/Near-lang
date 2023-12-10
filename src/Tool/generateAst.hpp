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
                writer << "#include main.cpp" << '\n';
                writer << '\n';
                writer << "#include <vector>" << '\n';
                writer << '\n';
                writer <<  "abstract class " << baseName << " {";

                writer << "}";
                writer.close();
            }
            std::for_each(types.begin(), types.end(), [baseName](const std::string& type) {
                std::istringstream iss(type);
                std::string className, fields;

                std::getline(iss, className, ':');
                std::getline(iss, fields);

                className.erase(className.find_last_not_of(" \t") + 1);
                fields.erase(fields.find_first_not_of(" \t"));
                defineType(writer, baseName, className, fields);
            });

            throw std::runtime_error("IoExpection");

        } catch (const std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    };
};