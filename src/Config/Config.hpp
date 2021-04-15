//
// Class for config
//

#pragma once

#include <iostream>

#include "WJson.hpp"

using namespace Wjson;

namespace MCLR
{
    const std::string configPath = "./config/config.json";

    class Config
    {
    private:
        static WJsonDoc _object;
        static bool _init;
    public:
        Config();
        inline ~Config() {};

        inline WJsonDoc &getConfig() { return _object; };
    };
}
