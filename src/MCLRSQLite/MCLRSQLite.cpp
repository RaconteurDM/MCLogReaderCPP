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

void MCLRSQLite::insertInTable(std::string table, std::map<std::string, std::string> values)
{
    std::string cmd = "INSERT INTO " + table + "(";
    std::string snames = "";
    std::string svalues = "";

    for (auto it = values.begin(); it != values.end(); it++) {
        snames += it->first + ",";
        svalues += it->second + ","; 
    }
    snames.pop_back();
    svalues.pop_back();
    cmd += snames + ") VALUES(" + svalues + ")";
    insertInTable(cmd);
}

static int callback(void *data, int argc, char **argv, char **azColName)
{
    MCLRSQLite().addCallback();
    for(int i = 0; i < argc; i++){
        if (azColName[i] != NULL && argv[i] != NULL)
            MCLRSQLite().setCallback(azColName[i], argv[i]);
    }
    return 0;
}

void MCLRSQLite::setCallback(std::string key, std::string value)
{
    _lastFetch.back()[key] = value;
}

void MCLRSQLite::addCallback()
{
    _lastFetch.push_back(std::map<std::string, std::string>());
}

std::vector<std::map<std::string, std::string>> MCLRSQLite::getCallback()
{
    std::vector<std::map<std::string, std::string>> ret = _lastFetch;

    MCLRSQLite().clearCallback();
    return ret;
}

void MCLRSQLite::clearCallback()
{
    _lastFetch.clear();
}

std::vector<std::map<std::string, std::string>> MCLRSQLite::fetchFromTable(std::string cmd)
{
    auto rgx = MCLRRegex("SELECT \\* FROM .*");
    char* messaggeError;
    int exit = 0;

    exit = sqlite3_exec(_DB, cmd.c_str(), &callback, 0, &messaggeError);
    MCLRLogs("db", "DB", "Fetch from table:\n\r" + cmd);
    if (!rgx.match(cmd))
        throw MCLRError("Error in table select: cmd is not a select command", "MCLRSQLite::fetchFromTable");
    if (exit != SQLITE_OK) {
        MCLRLogs("db", "DB", "ECHEC: " + std::string(messaggeError));
        sqlite3_free(messaggeError);
    } else {
        MCLRLogs("db", "DB", "Data fetched");
    }
    return getCallback();
}

void MCLRSQLite::closeDB()
{
    sqlite3_close(_DB);
    MCLRLogs("db", "DB", "Database closed");
}

bool MCLRSQLite::_init = true;

sqlite3* MCLRSQLite::_DB = NULL;

std::vector<std::map<std::string, std::string>> MCLRSQLite::_lastFetch = std::vector<std::map<std::string, std::string>>();