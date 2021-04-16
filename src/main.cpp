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
        MCLRSQLite().createTable("CREATE TABLE IF NOT EXISTS PERSON(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, SURNAME TEXT NOT NULL, AGE INT NOT NULL, ADDRESS CHAR(50), SALARY REAL )");
    } catch (const MCLR::MCLRError &e){
        std::cout << "Where: " + e.getWhere() + "What: " + e.getWhat() << std::endl;
    }

    //if (ac != 2)
    //    return 84;
    //return 0;
}