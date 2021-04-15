/**
 * @file Field.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Header for field parser
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
     * @brief Class for construct and contain SQL fields data
     * 
     */
    class Field
    {
    private:
        std::string _name;
        std::string _type;
        std::string _constraints;

        bool _hasConstraint;

        /**
         * @brief Verify the json data
         * 
         * @param FieldJSON 
         */
        void verifyField(const rapidjson::Value &FieldJSON);
    public:
        /**
         * @brief Construct a new Field object
         * 
         * @param FieldJSON 
         */

        Field(const rapidjson::Value &FieldJSON);

        /**
         * @brief Destroy the Field object
         * 
         */
        inline ~Field() {};

        /**
         * @brief Concat the field in SQL format and return it as a string
         * 
         * @return std::string 
         */
        std::string concat();
    };
} // namespace Field
