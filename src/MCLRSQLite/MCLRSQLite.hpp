/**
 * @file MCLRSQLite.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief SQLite header for MCLR app
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <map>
#include <vector>
#include "sqlite3.h"

namespace MCLR
{
	/**
	 * @brief Class handler for SQLite in MCLR app.
	 * 
	 */
	class MCLRSQLite
	{
	private:
		static bool _init;
		static sqlite3* _DB;
		static std::vector<std::map<std::string, std::string>> _lastFetch;

		/**
		 * @brief Initialize the DB
		 * 
		 */
		void initDB();
	public:
		/**
		 * @brief Initialize the DB if it's not yet
		 * 
		 */
		MCLRSQLite();

		/**
		 * @brief Destroy the MCLRSQLite object
		 * 
		 */
		inline ~MCLRSQLite() {};

		/**
		 * @brief Throw if the DB is not initialize yet
		 * 
		 */
		void verifyDBInit();

		/**
		 * @brief Create a table with 'cmd' as sql command
		 * 
		 * @param cmd 
		 */
		void createTable(std::string cmd);

		/**
		 * @brief Insert in a table with 'cmd' as sql command
		 * 
		 * @param cmd 
		 */
		void insertInTable(std::string cmd);

		void insertInTable(std::string table, std::map<std::string, std::string> values);

		/**
		 * @brief Return the values from last fetch
		 * 
		 * @return std::map<std::string, std::string> 
		 */
		std::vector<std::map<std::string, std::string>> getCallback();

		/**
		 * @brief Clear value from last fetch
		 * 
		 */
		void clearCallback();

		/**
		 * @brief Set a value for last created callback line
		 * 
		 * @param key 
		 * @param value 
		 */
		void setCallback(std::string key, std::string value);

		/**
		 * @brief Set a new call back line
		 * 
		 * @param key 
		 * @param value 
		 */
		void addCallback();

		/**
		 * @brief Fetch from a table with 'cmd' as sql command
		 * 
		 * @param cmd 
		 */
		std::vector<std::map<std::string, std::string>> fetchFromTable(std::string cmd);

		/**
		 * @brief Close the database. To be call at the end of program
		 * 
		 */
		void closeDB();
	};
}
