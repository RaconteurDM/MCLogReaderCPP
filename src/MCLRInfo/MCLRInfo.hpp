/**
 * @file MCLRInfo.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Header for intern operation of MCLR app
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <exception>

#include <unordered_map>

#include "Config.hpp"

using namespace MCLR;

namespace MCLR
{
    /**
     * @brief Basic error class for MCLR app, herit from std::exception. Can be throw
     * 
     */
    class MCLRError : public std::exception
    {
    private:
        std::string _what;
        std::string _where;
    public:
        /**
         * @brief Construct a new MCLRError object
         * 
         * @param what Describe the error
         * @param where Describe where the error occurs
         */
        inline MCLRError(std::string what, std::string where) : _where(where), _what(what) {};

        /**
         * @brief Construct a new MCLRError object from a precedent: keep the reason (what) and precise the location (where)
         * 
         * @param prevError Precedent MCLRError
         * @param where Location precision
         */
        inline MCLRError(const MCLRError &prevError, std::string where) : _what(prevError.getWhat()), _where(prevError.getWhere() + " in " + where) {};
        inline ~MCLRError() {};

        /**
         * @brief Get the error descriptor
         * 
         * @return std::string 
         */
        inline std::string getWhat() const { return _what; };

        /**
         * @brief Get the error position
         * 
         * @return std::string 
         */
        inline std::string getWhere() const { return _where; };

        /**
         * @brief Basically display the error
         * 
         */
        inline void dump() { std::cout << _where + ": " + _what << std::endl; };
    };

    /**
     * @brief Log class for MCLR app. Static class, all instance are the same
     * 
     */
    class MCLRLogs
    {
    private:
        static std::unordered_map<std::string, bool> _activeDisplay;
        static bool _init;

        /**
         * @brief Display the log message on output
         * 
         * @param categ 
         * @param message 
         */
        inline void display(std::string categ, std::string message) const { std::cout << "[" + categ + "]: " + message << std::endl; };
    public:
        /**
         * @brief Initialize logs configs
         * 
         */
        MCLRLogs();

        /**
         * @brief Take the log and perform the appropriate action with it
         * 
         * @param categ Used to identify the permissions from config and as a general identifier in the diffrents outputs
         * @param message Log message
         */
        MCLRLogs(std::string categ, std::string message);

        /**
         * @brief Take the log and perform the appropriate action with it
         * 
         * @param categ Used as to identify the permissions from config
         * @param categdisplay Used as a general identifier in the differents outputs
         * @param message Log message
         */
        MCLRLogs(std::string categ, std::string categdisplay, std::string message);

        /**
         * @brief Destroy the MCLRLogs object
         * 
         */
        inline ~MCLRLogs() {};
    };
    
} // namespace MCLR
