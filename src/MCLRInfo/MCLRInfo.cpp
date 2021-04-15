/**
 * @file MCLRInfo.cpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Code for MCLR interns Logs
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MCLRInfo.hpp"

using namespace MCLR;
using namespace MCLR;

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

MCLRLogs::MCLRLogs(std::string categ, std::string categdisplay, std::string message)
{
    if (MCLRLogs::_activeDisplay[categ])
        display(categdisplay, message);
}

std::unordered_map<std::string, bool> MCLRLogs::_activeDisplay;
bool MCLRLogs::_init = true;