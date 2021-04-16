##Makefile for MCLogReader

EXEC = ./MCLogReader.exe

SRC = src/*/*.cpp src/main.cpp

INCLUDE = -I./src\WJson -I./src\rapidjson\ -I.\src\MCLRInfo\ -I.\src\Config\ -I.\src\Modules\ -I.\src\Regex\ -I.\src\sqlite3 -I.\src\MCLRSQLite

FLAGS = -std=c++17

DEBUG = -g -g3 -ggdb

all:
	make compil

re:
	make fclean
	make compil

compil:
	g++ $(SRC) $(INCLUDE) $(FLAGS) -o $(EXEC)

fclean:
	del .\MCLogReader.exe