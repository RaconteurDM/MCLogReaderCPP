//
// Wrapper rapidJson
//

#pragma once

#include "document.h"

#include <string>
#include <fstream>
#include <streambuf>
#include <map>

using namespace rapidjson;

namespace Wjson {
    class WJsonDoc : public Document {
    public:
        WJsonDoc();
        ~WJsonDoc();

        void parseJsonFile(std::string file);
    };

    typedef enum {
        OBJECT = 1,
        ARRAY = 2,
        STRING = 3,
        DOUBLE = 4,
        INTEGER = 5,
        BOOL = 6
    } verifsTypes;

    class JsonValueVerif {
    public:
        inline JsonValueVerif() {};
        inline ~JsonValueVerif() {};

        bool verif(std::string field, verifsTypes hopedType, const rapidjson::Value &object, bool absPresence, bool absType);

    private:
        static std::map<verifsTypes, bool (rapidjson::Value::*)() const> verifsMap;
        static std::map<int, int> test;
    };
}