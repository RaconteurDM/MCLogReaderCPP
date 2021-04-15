//
// Methods def for MCRLLogs
//

#include "MCLRInfo.hpp"

using namespace MCLR;
using namespace Wjson;

MCLRLogs::MCLRLogs()
{
    auto _config = Config();

    if (MCLRLogs::_init) {
        JsonValueVerif().verif("MCRLLogs", OBJECT, _config.getConfig(), true, true);
        JsonValueVerif().verif("display", OBJECT, _config.getConfig()["MCRLLogs"], true, true);
        for (Value::ConstMemberIterator it = _config.getConfig()["MCRLLogs"]["display"].MemberBegin(); it != _config.getConfig()["MCRLLogs"]["display"].MemberEnd(); it++)
        {
            if (it->value.IsBool() && it->name.IsString())
            {
                MCLRLogs::_activeDisplay[it->name.GetString()] = it->value.GetBool();
            } else {
                throw MCLRError("Invalid log config", "MCLRLogs::MCLRLogs");
            }
        }
        MCLRLogs::_init = false;
    }
}

MCLRLogs::MCLRLogs(std::string categ, std::string message)
{
    if (MCLRLogs::_activeDisplay[categ])
        display(categ, message);
}

std::unordered_map<std::string, bool> MCLRLogs::_activeDisplay;
bool MCLRLogs::_init = true;