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
    std::map<std::string, std::string> testmap;

    if (ac != 3)
        return 84;
    testmap["name"] = "'" + std::string(av[1]) + "'";
    testmap["test"] = std::string(av[2]);
    try {
        MCLR::MCLRLogs();
        MCLRSQLite().createTable("CREATE TABLE IF NOT EXISTS Files(id integer PRIMARY KEY, name text UNIQUE, test integer)");
        MCLRSQLite().insertInTable("Files", testmap);
        std::vector<std::map<std::string, std::string>> test = MCLRSQLite().fetchFromTable("SELECT * FROM Files");
        for (auto it = test.begin(); it != test.end(); it++) {
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