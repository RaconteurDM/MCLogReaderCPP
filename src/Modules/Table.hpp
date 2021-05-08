/**
 * @file Table.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Header for table class
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

using namespace MCLR;

namespace MCLR
{
    /**
     * @brief Class for construct and contain SQL tables data
     * 
     */
    class Table
    {
    private:
        std::string _name;
        std::vector<std::string> _fieldList;
        std::vector<std::string> _constraintsList;
    
        bool _hasConstraint;
    
        /**
         * @brief Verify the json data
         * 
         * @param FieldJSON 
         */
        void verifyTable(const rapidjson::Value &TableJSON);
    public:
        /**
         * @brief Construct a new Table object
         * 
         * @param TableJSON 
         */
        Table(const rapidjson::Value &TableJSON);

        /**
         * @brief Destroy the Table object
         * 
         */
        inline ~Table() {};

        /**
         * @brief Concat the table in SQL format and return it as a string
         * 
         * @return std::string 
         */
        std::string concat();

        inline std::string getName() { return (_name); };
    };
}