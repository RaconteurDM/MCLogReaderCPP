//
// Methods definition for modules
//

#include "Module.hpp"
#include "WJson.hpp"
#include "MCLRInfo.hpp"

#include "Table.hpp"

using namespace Modules;
using namespace MCLRInfo;

Module::Module(std::string JSONfile)
{
    _JSON.parseJsonFile(JSONfile);
    verifyModule(JSONfile);
    MCLRLogs("Module", "Create " + _name + " module");
    for (Value::ConstValueIterator itr = _JSON["tables"].Begin(); itr != _JSON["tables"].End(); ++itr) {
        if (itr->IsObject())
            std::cout << Table(*itr).concat() << std::endl;
    }
    MCLRLogs("Module", "Module " + _name + " created");
}

void Module::verifyModule(std::string JSONfile)
{
    if (!_JSON.IsObject()) {
        throw MCLRError("Invalid module: " + JSONfile, "Module::verifyModule");
    }
    JsonValueVerif().verif("settings", OBJECT, _JSON, true, true);
    JsonValueVerif().verif("name", STRING, _JSON["settings"], true, true);
    _name = _JSON["settings"]["name"].GetString();
    _hasParents = JsonValueVerif().verif("parents", ARRAY, _JSON, false, true);
    JsonValueVerif().verif("tables", ARRAY, _JSON, true, true);
}