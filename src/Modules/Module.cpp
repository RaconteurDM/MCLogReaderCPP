/**
 * @file Module.cpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Code for Module class
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Module.hpp"
#include "WJson.hpp"
#include "MCLRInfo.hpp"

#include "Table.hpp"

using namespace MCLR;
using namespace MCLR;

Module::Module(std::string JSONfile)
{
    _JSON.parseJsonFile(JSONfile);
    verifyModule(JSONfile);
    MCLRLogs("ModuleLoad", "Create " + _name + " module");
    for (Value::ConstValueIterator itr = _JSON["tables"].Begin(); itr != _JSON["tables"].End(); ++itr) {
        if (itr->IsObject())
            _tableList.push_back(Table(*itr));
    }
    MCLRLogs("ModuleLoad", "Module " + _name + " created");
}

void Module::verifyModule(std::string JSONfile)
{
    if (!_JSON.IsObject()) {
        throw MCLRError("Invalid module: " + JSONfile, "Module::verifyModule");
    }
    JsonValueVerif().verif("settings", OBJECT, _JSON, true, true);
    JsonValueVerif().verif("name", STRING, _JSON["settings"], true, true);
    _name = _JSON["settings"]["name"].GetString();
    JsonValueVerif().verif("tables", ARRAY, _JSON, true, true);
}