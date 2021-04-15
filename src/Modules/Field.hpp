//
// classes contenant les spécifications des fields
//

#pragma once

#include <iostream>
#include <vector>
#include "WJson.hpp"

using namespace Wjson;

namespace MCLR
{
    class Field
    {
    private:
        std::string _name;
        std::string _type;
        std::string _constraints;

        bool _hasConstraint;
    public:
        Field(const rapidjson::Value &FieldJSON);
        inline ~Field() {};

        std::string concat();
        void verifyField(const rapidjson::Value &FieldJSON);
    };
} // namespace Field
