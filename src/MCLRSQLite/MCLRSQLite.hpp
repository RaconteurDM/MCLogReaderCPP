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
#include "sqlite3.h"

namespace MCLR
{
	/**
	 * @brief Class handler for SQLite in MCLR app
	 * 
	 */
	class MCLRSQLite
	{
	private:
		static bool _init;
		static sqlite3* _DB;

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
		 * @brief Close the database. To be call at the end of program
		 * 
		 */
		void closeDB();
	};
}
