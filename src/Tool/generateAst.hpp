#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <algorithm>
#include "include/stringSplit.hpp"
#include "include/stringTrim.hpp"
class GenerateAst {

public:
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

            for (std::string& type : types) {
                std::vector<std::string> tokens {split(type, ':')};

                if (tokens.size() >= 2) {
                    std::string className {trim(tokens.at(0))};
                    std::string fields {trim(tokens.at(1))};
                    defineType(writer, baseName, className, fields);
                }
            }

            throw std::runtime_error("IoExpection");

        } catch (const std::exception& err) {
            std::cerr << err.what() << '\n';
        }
    };

private:
    static void defineType(std::ofstream& writer, 
    const std::string& baseName, 
    const std::string& className, 
    const std::string& fieldList)
    {
        writer << " class " << className << " : public"  << baseName << " {" << '\n';
        writer << "public: " << '\n';
        writer << " " << className << "(" << fieldList << ") {" << '\n';

        std::vector<std::string> fields {split(fieldList, ',')};
        for (const std::string& field: fields) {
            std::string name {split(field, ' ')[1]};
            writer << " this->" << name << " = " << name << ";" << '\n';
        }

        writer << " }" << '\n';

        writer << '\n';
        for (const std::string& field: fields) {
            writer << " " << field << ';' << '\n';
        }

        writer << " };" << '\n';
    }

};