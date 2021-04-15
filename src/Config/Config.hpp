/**
 * @file Config.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Configaration parser header
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>

#include "WJson.hpp"

using namespace MCLR;

namespace MCLR
{
    /**
     * @brief Const path to config file
     * 
     */
    const std::string configPath = "./config/config.json";

    /**
     * @brief Generic class, contain only static members. Initialize config on first instanciation.
     * 
     */
    class Config
    {
    private:
        static WJsonDoc _object;
        static bool _init;
    public:
        /**
         * @brief Construct a new Config object
         * 
         */
        Config();

        /**
         * @brief Destroy the Config object
         * 
         */
        inline ~Config() {};

        /**
         * @brief Get the config as a json object
         * 
         * @return WJsonDoc& 
         */
        inline WJsonDoc &getConfig() { return _object; };
    };
}
