/**
 * @file Config.cpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Code for configuration parser
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Config.hpp"
#include "MCLRInfo.hpp"

using namespace MCLR;
using namespace MCLR;
using namespace MCLR;

WJsonDoc Config::_object;
bool Config::_init = true;

Config::Config() {
    if(Config::_init)
    {
        _object.parseJsonFile(configPath);
        Config::_init = false;
        if (!_object.IsObject())
            throw MCLRError("Invalid config", "Config");
    }
}