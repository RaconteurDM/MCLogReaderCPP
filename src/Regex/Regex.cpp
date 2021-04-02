//
// Regex method cpp
//

#include "Regex.hpp"

bool MCLRRegex::match(std::string str)
{
    return (std::regex_match(str, _rgx));
}