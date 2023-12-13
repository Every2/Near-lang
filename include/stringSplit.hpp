#ifndef NEAR_LANG_STRINGSPLIT_HPP
#define NEAR_LANG_STRINGSPLIT_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(s);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}


#endif
