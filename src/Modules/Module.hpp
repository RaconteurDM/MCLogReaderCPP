/**
 * @file Module.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Header for module class
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include "WJson.hpp"

#include "Table.hpp"

using namespace MCLR;

namespace MCLR
{
    /**
     * @brief Class for construct and contain module data
     * 
     */
    class Module
    {
    private:
        WJsonDoc _JSON;
        std::vector<Table> _tableList;
        std::string _name;

        /**
         * @brief Verify the json data
         * 
         * @param JSONfile 
         */
        void verifyModule(std::string JSONfile);

    public:
        /**
         * @brief Construct a new Module object
         * 
         * @param JSONFile 
         */
        Module(std::string JSONFile);

        /**
         * @brief Destroy the Module object
         * 
         */
        inline ~Module() {};

        /**
         * @brief Load all instrcutions for SQL creations of all the module's tables from JSON
         * 
         * @param JSONfile 
         */
        void loadTables(std::string JSONfile);
    };
}
