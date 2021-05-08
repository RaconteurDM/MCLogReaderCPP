//
// MCLogReader Main File
//

#include <iostream>

#include "WJson.hpp"
#include "Module.hpp"
#include "MCLRInfo.hpp"
#include "Regex.hpp"
#include "MCLRSQLite.hpp"

using namespace MCLR;

int main(int ac, char **av)
{
    SQLFieldValues testmap;
    SQLFieldValues testmap2;

    if (ac != 3)
        return 84;
    testmap.addFieldValue("name", std::string(av[1]));
    testmap2.addFieldValue("fileid", std::stoi(std::string(av[2])));
    testmap2.addFieldValue("message", "Lol, qui aurait cru");
    try {
        MCLR::MCLRLogs();
        std::string str = "modules/basics/reader.json";
        Module test(str);
        test.initSQL();
        MCLRSQLite().insertInTable("Files", testmap);
        MCLRSQLite().insertInTable("lines", testmap2);
        std::vector<std::map<std::string, std::string>> testrep = MCLRSQLite().fetchFromTable("Files");
        for (auto it = testrep.begin(); it != testrep.end(); it++) {
            std::cout << "{" << std::endl;
            for (auto itt = it->begin(); itt != it->end(); itt++)
                std::cout << "    " << itt->first << " " << itt->second << std::endl;
            std::cout << "}" << std::endl;
        }
        MCLRSQLite().closeDB();
    } catch (const MCLR::MCLRError &e){
        std::cout << "Where: " + e.getWhere() + "\nWhat: " + e.getWhat() << std::endl;
    }
    return 0;
}