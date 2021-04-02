//
// MCLogReader Main File
//

#include <iostream>

#include "WJson.hpp"
#include "Module.hpp"
#include "MCLRInfo.hpp"

using namespace Modules;
using namespace MCLRInfo;

int main(void)
{
    try {
        MCLRLogs();
        Module("./modules/basics.json");
    } catch (const MCLRError &e){
        std::cout << "Where: " + e.getWhere() + "What: " + e.getWhat() << std::endl;
    }
}