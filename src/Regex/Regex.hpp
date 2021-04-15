/**
 * @file Regex.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Header for MCLR regex
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <regex>
#include <vector>

namespace MCLR
{
    /**
     * @brief Regex class for MCLR
     * 
     */
    class MCLRRegex
    {
    private:
        std::string _rgx_str;
        std::regex _rgx;

        /**
         * @brief Make the std::regex object
         * 
         */
        inline void compileRgx() { _rgx = std::regex(_rgx_str); };

    public:
        /**
         * @brief Construct a new MCLRRegex object from a format string
         * 
         * @param rgx 
         */
        inline MCLRRegex(std::string rgx) : _rgx_str(rgx) { compileRgx(); };

        /**
         * @brief Destroy the MCLRRegex object
         * 
         */
        inline ~MCLRRegex(){};

        /**
         * @brief Verify if 'str' match the regex 
         * 
         * @param str 
         * @return true 
         * @return false 
         */
        bool match(std::string &str);

        /**
         * @brief Verify if 'str' contain a substring matching the regex
         * 
         * @param str 
         * @return true 
         * @return false 
         */
        bool contain(std::string &str);

        /**
         * @brief Make a list of token matching the regex in 'str'
         * 
         * @param str 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> tokenize(std::string str);

        /**
         * @brief Split 'str' by regex ans return an array of the diffrent parts
         * 
         * @param str 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> split(std::string str);

        /**
         * @brief Replace the parts matching the regex by 'replace' in 'str'
         * 
         * @param str 
         * @param replace 
         * @return std::string 
         */
        std::string replace(std::string &str, std::string &replace);
    };
}
