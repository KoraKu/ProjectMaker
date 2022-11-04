#ifndef PROJECT_H
#define PROJECT_H
#endif


#include "const.h"

#define MAKEFILE_C ="COMPILER:= gcc\
FLAGS := #add flags here. examples : -Wall\
\
FILENAME := main.c\
TARGET := bin/main\
\
# Getting all sources files in src folder\
SOURCES = $(wildcard src/*.c)\
# Converting source files names to objects files\
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))\
\
#Link main.c with every object\
$(TARGET) : $(SOURCES) $(OBJECTS)\
\tmkdir -p ./bin\
\t$(COMPILER) $(FILENAME) $(wildcard obj/*.o) -o $(TARGET)\
\
#computes every object from sources\
obj/%.o : src/%.c\
\tmkdir -p ./obj\
\t$(COMPILER) -c $^ -o $@\
\
#Clear eveything and rebuilds it\
re : clear $(TARGET)\
\
#Runs the program\
run : $(TARGET)\
\t./$(TARGET)\
\
#Clear workspace of .o files and executable\
clear :\
\trm -f $(OBJECTS)\
\trm -f $(TARGET)"

#define MAKEFILE_CPP = "COMPILER:= g++\
FLAGS := #add flags here. examples : -Wall\
\
FILENAME := main.cpp\
TARGET := bin/main\
\
# Getting all sources files in src folder\
SOURCES = $(wildcard src/*.cpp)\
# Converting source files names to objects files\
OBJECTS = $(patsubst src/%.cpp, obj/%.o, $(SOURCES))\
\
#Link main.c with every object\
$(TARGET) : $(SOURCES) $(OBJECTS)\
\tmkdir -p ./bin\
\t$(COMPILER) $(FILENAME) $(wildcard obj/*.o) -o $(TARGET)\
\
#computes every object from sources\
obj/%.o : src/%.cpp\
\tmkdir -p ./obj\
\t$(COMPILER) -c $^ -o $@\
\
#Clear eveything and rebuilds it\
re : clear $(TARGET)\
\
#Runs the program\
run : $(TARGET)\
\t./$(TARGET)\
\
#Clear workspace of .o files and executable\
clear :\
\trm -f $(OBJECTS)\
\trm -f $(TARGET)"

int newpj(int argc, char *argv[], int language);