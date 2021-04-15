/**
 * @file WJson.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Header for rapidJson wrapper
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "document.h"

#include <string>
#include <fstream>
#include <streambuf>
#include <map>

using namespace rapidjson;

namespace MCLR {
    /**
     * @brief Wrapper de Document rapidJson
     * 
     */
    class WJsonDoc : public Document {
    public:
        /**
         * @brief Construct a new WJsonDoc object
         * 
         */
        WJsonDoc();
        /**
         * @brief Destroy the WJsonDoc object
         * 
         */
        ~WJsonDoc();

        /**
         * @brief Initialize Json object from Json file
         * 
         * @param file 
         */
        void parseJsonFile(std::string file);
    };

    /**
     * @brief Types d'objets Json
     * 
     */
    typedef enum {
        OBJECT = 1,
        ARRAY = 2,
        STRING = 3,
        DOUBLE = 4,
        INTEGER = 5,
        BOOL = 6
    } verifsTypes;

    /**
     * @brief Static class for Json value verification
     * 
     */
    class JsonValueVerif {
    public:
        /**
         * @brief Construct a new Json Value Verif object
         * 
         */
        inline JsonValueVerif() {};

        /**
         * @brief Destroy the Json Value Verif object
         * 
         */
        inline ~JsonValueVerif() {};

        /**
         * @brief Verify if the field 'field' of type 'hopedType' exist in the object 'object'
         * 
         * @param field 
         * @param hopedType 
         * @param object 
         * @param absPresence If true, throw an error if the field does not exist
         * @param absType If true, throw an error if the field is in the wrong type
         * @return true 
         * @return false 
         */
        bool verif(std::string field, verifsTypes hopedType, const rapidjson::Value &object, bool absPresence, bool absType);

    private:
        static std::map<verifsTypes, bool (rapidjson::Value::*)() const> verifsMap;
        static std::map<int, int> test;
    };
}