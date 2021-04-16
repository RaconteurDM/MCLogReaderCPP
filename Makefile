##Makefile for MCLogReader

EXEC = ./MCLogReader.exe

CSRC = src/sqlite3/sqlite3.c

SRC = src/*/*.cpp src/main.cpp

INCLUDE = -I./src\WJson -I./src\rapidjson\ -I.\src\MCLRInfo\ -I.\src\Config\ -I.\src\Modules\ -I.\src\Regex\ -I.\src\sqlite3 -I.\src\MCLRSQLite

FLAGS = -std=c++17

DEBUG = -g -g3 -ggdb

all:
	make compil

re:
	make fclean
	make compil

compilc:
	gcc $(CSRC) -c

compil:
	make compilc
	g++ $(SRC) $(INCLUDE) $(FLAGS) -o $(EXEC) *.o

clean:
	del src/sqlite3/sqlite3.o

fclean:
	make clean
	del .\MCLogReader.exe