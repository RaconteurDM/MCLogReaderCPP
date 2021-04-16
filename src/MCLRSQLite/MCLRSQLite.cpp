/**
 * @file SQLite.cpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief SQLite code for MCLR app
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MCLRSQLite.hpp"
#include "sqlite3.h"
#include "MCLRInfo.hpp"

using namespace MCLR;

SQLite::SQLite()
{
    if (_init)
    {
        initDB();
    }
}

void SQLite::initDB()
{
    int exit = 0;
    exit = sqlite3_open("db/db.db", &_DB);
  
    if (exit) {
        throw MCLRError("Error in when opening DB", "SQLite::initDB");
    }
    else
        MCLRLogs("db", "DB", "Database opened");
}

void SQLite::createTable(std::string cmd)
{
    int exit = 0;
    char* messaggeError;
    exit = sqlite3_exec(_DB, cmd.c_str(), NULL, 0, &messaggeError);
    MCLRLogs("db", "DB", "Creating table:\n\r" + cmd);
    if (exit != SQLITE_OK) {
        sqlite3_free(messaggeError);
        throw MCLRError("Error in table initialazing", "SQLite::createTable");
    }
    MCLRLogs("db", "DB", "Table created");
}

void SQLite::closeDB()
{
    sqlite3_close(_DB);
    MCLRLogs("db", "DB", "Database closed");
}

bool SQLite::_init = true;
sqlite3* SQLite::_DB = NULL;