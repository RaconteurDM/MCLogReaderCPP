//
// MCLogReader Main File
//

#include <iostream>

#include "WJson.hpp"
#include "Module.hpp"
#include "MCLRInfo.hpp"
#include "Regex.hpp"

using namespace Modules;
using namespace MCLRInfo;

int main(int ac, char **av)
{
    //try {
    //    MCLRLogs();
    //    Module("./modules/basics.json");
    //} catch (const MCLRError &e){
    //    std::cout << "Where: " + e.getWhere() + "What: " + e.getWhat() << std::endl;
    //}

    if (ac != 2)
        return 84;
    auto test = MCLRRegex("\\[.*\\]");
    if (test.match(av[1]))
        std::cout << "Good" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}