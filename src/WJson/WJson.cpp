/**
 * @file WJson.cpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief Code for rapidJson wrapper
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "WJson.hpp"
#include "MCLRInfo.hpp"
#include <iostream>

using namespace MCLR;
using namespace MCLR;

WJsonDoc::WJsonDoc() : Document() {
}

WJsonDoc::~WJsonDoc() {
}

void WJsonDoc::parseJsonFile(std::string file)
{
    std::ifstream t(file);
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());

    this->Parse(str.c_str());
    if (this->GetType() == 0)
        throw MCLRError(file + ": Invalid JSON", "WJsonDoc::parseJsonFile");
}

bool JsonValueVerif::verif(std::string field, verifsTypes hopedType, const rapidjson::Value &object, bool absPresence, bool absType)
{
    bool state = true;
    if (!object.HasMember(field.c_str()))
    {
        if (absPresence)
            throw MCLRError("Missing field '" + field + "'", "");
        state = false;
    } else if (!(object[field.c_str()].*verifsMap[hopedType])())
    {
        if (absType)
            throw MCLRError("Wrong type for field '" + field + "'", "");
        state = false;
    }
    return (state);
}

std::map<verifsTypes, bool (rapidjson::Value::*)() const> JsonValueVerif::verifsMap = {{OBJECT, rapidjson::Value::IsObject}, {ARRAY, rapidjson::Value::IsArray}, {STRING, rapidjson::Value::IsString}, {INTEGER, rapidjson::Value::IsInt}, {DOUBLE, rapidjson::Value::IsDouble}, {BOOL, rapidjson::Value::IsBool}};