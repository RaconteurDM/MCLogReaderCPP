//
// Methods definition for Fields
//

#include "Module.hpp"
#include "WJson.hpp"
#include "MCLRInfo.hpp"

#include "Field.hpp"

using namespace MCLR;
using namespace MCLR;

Field::Field(const rapidjson::Value &FieldJSON)
{
    verifyField(FieldJSON);
    if (_hasConstraint)
        _constraints = FieldJSON["constraints"].GetString();
    _type = FieldJSON["type"].GetString();
}

void Field::verifyField(const rapidjson::Value &FieldJSON)
{
    _name = "";
    if (!FieldJSON.IsObject()) {
        throw MCLRError("Trying to create a an invalid Field", "");
    }
    JsonValueVerif().verif("name", STRING, FieldJSON, true, true);
    _name = FieldJSON["name"].GetString();
    JsonValueVerif().verif("type", STRING, FieldJSON, true, true);
    _hasConstraint = JsonValueVerif().verif("constraints", STRING, FieldJSON, false, true);
}

std::string MCLR::Field::concat()
{
    auto ret = _name + " " + _type;
    if (_hasConstraint)
        ret = ret  + " " +  _constraints; 
    return ret;
}