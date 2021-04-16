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
    try {
        MCLR::MCLRLogs();
        MCLRSQLite().createTable("CREATE TABLE IF NOT EXISTS Files(id integer PRIMARY KEY, name text UNIQUE)");
        MCLRSQLite().insertInTable("INSERT INTO Files('name') VALUES('test2')");
        MCLRSQLite().closeDB();
    } catch (const MCLR::MCLRError &e){
        std::cout << "Where: " + e.getWhere() + "\nWhat: " + e.getWhat() << std::endl;
    }

    //if (ac != 2)
    //    return 84;
    //return 0;
}