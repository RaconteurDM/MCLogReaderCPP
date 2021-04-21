/**
 * @file MCLRSQLite.cpp
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
#include "Regex.hpp"

using namespace MCLR;

MCLRSQLite::MCLRSQLite()
{
    if (_init)
    {
        initDB();
        _init = false;
    }
}

void MCLRSQLite::initDB()
{
    int exit = 0;
    exit = sqlite3_open("db/db.db", &_DB);
  
    if (exit) {
        throw MCLRError("Error in when opening DB", "MCLRSQLite::initDB");
    }
    else
        MCLRLogs("db", "DB", "Database opened");
}

void MCLRSQLite::createTable(std::string cmd)
{
    auto rgx = MCLRRegex("CREATE TABLE .*\\(.*\\)");
    int exit = 0;
    char* messaggeError;
    exit = sqlite3_exec(_DB, cmd.c_str(), NULL, 0, &messaggeError);
    MCLRLogs("db", "DB", "Creating table:\n\r" + cmd);
    if (!rgx.match(cmd))
        throw MCLRError("Error in table initialazing: cmd is not a create command", "MCLRSQLite::createTable");
    if (exit != SQLITE_OK) {
        MCLRLogs("db", "DB", "ECHEC: " + std::string(messaggeError));
        sqlite3_free(messaggeError);
        throw MCLRError("Error in table initialazing", "MCLRSQLite::createTable");
    }
    MCLRLogs("db", "DB", "Table created");
}

void MCLRSQLite::insertInTable(std::string cmd)
{
    auto rgx = MCLRRegex("INSERT INTO .*\\(.*\\) VALUES\\(.*\\)");
    char* messaggeError;
    int exit = 0;

    exit = sqlite3_exec(_DB, cmd.c_str(), NULL, 0, &messaggeError);
    MCLRLogs("db", "DB", "Insert in table:\n\r" + cmd);
    if (!rgx.match(cmd))
        throw MCLRError("Error in table insert: cmd is not an insert command", "MCLRSQLite::insertInTable");
    if (exit != SQLITE_OK) {
        MCLRLogs("db", "DB", "ECHEC: " + std::string(messaggeError));
        sqlite3_free(messaggeError);
    } else {
        MCLRLogs("db", "DB", "Data inserted");
    }
}

static int callback(void *data, int argc, char **argv, char **azColName)
{
    MCLRSQLite().clearCallback();
    for(int i = 0; i < argc; i++){
        if (azColName[i] != NULL && argv[i] != NULL)
            MCLRSQLite().setCallback(azColName[i], argv[i]);
    }
    return 0;
}

void MCLRSQLite::setCallback(std::string key, std::string value)
{
    _lastFetch[key] = value;
}

std::map<std::string, std::string> MCLRSQLite::getCallback()
{
    return _lastFetch;
}

void MCLRSQLite::clearCallback()
{
    _lastFetch.clear();
}

void MCLRSQLite::fetchFromTable(std::string cmd)
{
    auto rgx = MCLRRegex("SELECT \\* FROM .*");
    char* messaggeError;
    int exit = 0;

    exit = sqlite3_exec(_DB, cmd.c_str(), NULL, 0, &messaggeError);
    MCLRLogs("db", "DB", "Fetch from table:\n\r" + cmd);
    if (!rgx.match(cmd))
        throw MCLRError("Error in table select: cmd is not a select command", "MCLRSQLite::fetchFromTable");
    if (exit != SQLITE_OK) {
        MCLRLogs("db", "DB", "ECHEC: " + std::string(messaggeError));
        sqlite3_free(messaggeError);
    } else {
        MCLRLogs("db", "DB", "Data fetched");
    }
}

void MCLRSQLite::closeDB()
{
    sqlite3_close(_DB);
    MCLRLogs("db", "DB", "Database closed");
}

bool MCLRSQLite::_init = true;

sqlite3* MCLRSQLite::_DB = NULL;

std::map<std::string, std::string> MCLRSQLite::_lastFetch = std::map<std::string, std::string>();