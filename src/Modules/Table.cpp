//
// Methods definition for tables
//

#include "Module.hpp"
#include "WJson.hpp"
#include "MCLRInfo.hpp"

#include "Table.hpp"
#include "Field.hpp"

using namespace MCLR;
using namespace MCLR;

MCLR::Table::Table(const rapidjson::Value &TableJSON)
{
    verifyTable(TableJSON);
    MCLRLogs("ModuleLoad", "TableLoad", "Create " + _name + " table");
    for (Value::ConstValueIterator itr = TableJSON["fields"].Begin(); itr != TableJSON["fields"].End(); ++itr) {
        if (!itr->IsObject())
            throw MCLRError("Invalid field: not a JSON object (table name: \"" +  _name + "\")", "Table::Table");
        _fieldList.push_back(Field(itr->GetObject()).concat());
    }
    if (_hasConstraint) {
        for (Value::ConstValueIterator itr = TableJSON["constraints"].Begin(); itr != TableJSON["constraints"].End(); ++itr) {
            if (!itr->IsString())
                throw MCLRError("Invalid constraints: not a JSON string (table name: \"" +  _name + "\")", "Table::Table");
            _constraintsList.push_back(itr->GetString());
        }        
    }
    MCLRLogs("ModuleLoad", "TableLoad", "Table " + _name + " created");
}

void MCLR::Table::verifyTable(const rapidjson::Value &TableJSON)
{
    _name = "";
    if (!TableJSON.IsObject()) {
        throw MCLRError("Trying to create a an invalid Table", "Table::verifyTable");
    }
    JsonValueVerif().verif("name", STRING, TableJSON, true, true);
    _name = TableJSON["name"].GetString();
    JsonValueVerif().verif("fields", ARRAY, TableJSON, true, true);
    _hasConstraint = JsonValueVerif().verif("constraints", ARRAY, TableJSON, false, true);
}

std::string MCLR::Table::concat()
{
    std::string res = "";
    for (auto it = _fieldList.begin(); it != _fieldList.end(); it++)
    {
        res += *it;
        if (it + 1 != _fieldList.end())
            res += ", ";
    }
    for (auto it = _constraintsList.begin(); it != _constraintsList.end(); it++)
    {
        res += ", ";
        res += *it;
    }
    return res;
}