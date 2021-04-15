//
// MCLogReader Main File
//

#include <iostream>

#include "WJson.hpp"
#include "Module.hpp"
#include "MCLRInfo.hpp"
#include "Regex.hpp"

using namespace MCLR;

int main(int ac, char **av)
{
    try {
        MCLR::MCLRLogs();
        MCLR::Module("./modules/basics/reader.json");
    } catch (const MCLR::MCLRError &e){
        std::cout << "Where: " + e.getWhere() + "What: " + e.getWhat() << std::endl;
    }

    //if (ac != 2)
    //    return 84;
    //return 0;
}