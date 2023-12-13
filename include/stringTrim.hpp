#ifndef NEAR_LANG_STRINGTRIM_HPP
#define NEAR_LANG_STRINGTRIM_HPP
#include <string>

std::string trim_left(const std::string& str) {
    const std::string pattern {"\f\n\r\t\v"};
    return str.substr(str.find_first_not_of(pattern));
}

std::string trim_right(const std::string& str) {
    const std::string pattern {"\f\n\r\t\v"};
    return str.substr(0,str.find_last_not_of(pattern) + 1);
}

std::string trim(const std::string& str) {
    return trim_left(trim_right(str));
}

#endif