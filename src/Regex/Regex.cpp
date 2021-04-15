/**
 * @file Regex.cpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Regex for MCLR
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Regex.hpp"

bool MCLR::MCLRRegex::match(std::string &str)
{
    return (std::regex_match(str, _rgx));
}

bool MCLR::MCLRRegex::contain(std::string &str)
{
    return (std::regex_search(str, _rgx));
}

std::string MCLR::MCLRRegex::replace(std::string &str, std::string &replace)
{
    return (std::regex_replace(str, _rgx, replace));
}

std::vector<std::string> MCLR::MCLRRegex::tokenize(std::string str)
{
    std::vector<std::string> res;
    std::sregex_token_iterator defaultToken;
    std::sregex_token_iterator Tokens(str.begin(), str.end(), _rgx, 0);

    while (Tokens != defaultToken)
    {
        res.push_back(*Tokens);
        Tokens++;
    }
    return (res);
}

std::vector<std::string> MCLR::MCLRRegex::split(std::string str)
{
    std::vector<std::string> res;
    std::sregex_token_iterator defaultToken;
    std::sregex_token_iterator Tokens(str.begin(), str.end(), _rgx, -1);

    while (Tokens != defaultToken)
    {
        res.push_back(*Tokens);
        Tokens++;
    }
    return (res);
}