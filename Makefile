##Makefile for MCLogReader

EXEC = ./MCLogReader.exe

CSRC = src/sqlite3/sqlite3.c

SRC = src/*/*.cpp src/main.cpp

INCLUDE = -I./src\WJson -I./src\rapidjson\ -I.\src\MCLRInfo\ -I.\src\Config\ -I.\src\Modules\ -I.\src\Regex\ -I.\src\sqlite3 -I.\src\MCLRSQLite

FLAGS = -std=c++17 -DTHREADSAFE=1

DEBUG = -g -g3 -ggdb

all:
	make compil

re:
	make fclean
	make compilc
	make compil

compilc:
	gcc $(CSRC) -c

compil:
	g++ $(SRC) $(INCLUDE) $(FLAGS) -o $(EXEC) *.o $(DEBUG)

clean:
	if exist sqlite3.o del sqlite3.o

fclean:
	make clean
	if exist .\MCLogReader.exe del .\MCLogReader.exe