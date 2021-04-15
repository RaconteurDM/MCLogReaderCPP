//
// Code for config
//

#include "Config.hpp"
#include "MCLRInfo.hpp"

using namespace MCLR;
using namespace MCLR;
using namespace Wjson;

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