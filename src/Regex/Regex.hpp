//
// Regex class custom
//

#pragma once

#include <iostream>
#include <regex>
#include <vector>

class MCLRRegex
{
private:
    std::string _rgx_str;
    std::regex _rgx;

    inline void compileRgx() { _rgx = std::regex(_rgx_str); };

public:
    inline MCLRRegex(std::string rgx) : _rgx_str(rgx) { compileRgx(); };
    inline ~MCLRRegex() {};

    bool match(std::string str);
    std::vector<std::string> tokenize(std::string str);
    std::vector<std::string> split(std::string str);
};
