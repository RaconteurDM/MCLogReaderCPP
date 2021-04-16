/**
 * @file SQLite.hpp
 * @author Paul (paul.brancieq@epitech.eu)
 * @brief SQLite header for MCLR app
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

namespace MCLR
{
	class SQLite
	{
	private:
		static bool _init;
		static sqlite3* _DB;

		void initDB();
	public:
		SQLite();
		inline ~SQLite() {};

		void verifyDBInit();
		void createTable(std::string cmd);
		void closeDB();
	};
}
