//
// Classe throw error
//

#pragma once

#include <iostream>
#include <exception>

#include <unordered_map>

#include "Config.hpp"

using namespace MCLR;

namespace MCLR
{
    class MCLRError : public std::exception
    {
    private:
        std::string _what;
        std::string _where;
    public:
        inline MCLRError(std::string what, std::string where) : _where(where), _what(what) {};
        inline MCLRError(const MCLRError &prevError, std::string where) : _what(prevError.getWhat()), _where(prevError.getWhere() + " in " + where) {};
        inline ~MCLRError() {};

        inline std::string getWhat() const { return _what; };
        inline std::string getWhere() const { return _where; };

        inline void dump() { std::cout << _where + ": " + _what << std::endl; };
    };

    class MCLRLogs
    {
    private:
        static std::unordered_map<std::string, bool> _activeDisplay;
        static bool _init;

        inline void display(std::string categ, std::string message) const { std::cout << "[" + categ + "]: " + message << std::endl; };
    public:
        MCLRLogs();
        MCLRLogs(std::string categ, std::string message);
        inline ~MCLRLogs() {};
    };
    
} // namespace MCLR
