//
// classes contenant les spécifications des tables
//

#pragma once

#include <iostream>
#include <vector>
#include "WJson.hpp"

using namespace Wjson;

namespace Modules
{
    class Table
    {
    private:
        std::string _name;
        std::vector<std::string> _fieldList;
        std::vector<std::string> _constraintsList;
    
        bool _hasConstraint;
    
        void verifyTable(const rapidjson::Value &TableJSON);
    public:
        Table(const rapidjson::Value &TableJSON);
        inline ~Table() {};
        std::string concat();
    };
}