//
// classes contenant les spécifications des modules
//

#pragma once

#include <iostream>
#include <vector>
#include "WJson.hpp"

#include "Table.hpp"

using namespace Wjson;

namespace Modules
{
    class Module
    {
    private:
        WJsonDoc _JSON;
        std::vector<Table> _tableList;
        std::string _name;
        bool _hasParents;

    public:
        Module(std::string JSONFile);
        inline ~Module() {};

        void loadTables(std::string JSONfile);
        void verifyModule(std::string JSONfile);
    };
}
