#ifndef PROJECT_H
#define PROJECT_H
#endif


#include "const.h"

#define MAKEFILE_C "COMPILER:= gcc\n\
FLAGS := #add flags here. examples : -Wall\n\
\n\
FILENAME := main.c\n\
TARGET := bin/main\n\
\n\
# Getting all sources files in src folder\n\
SOURCES = $(shell find src/ -name '*.c')\n\
# Converting source files names to objects files\n\
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))\n\
# Get all dirs\n\
DIRS = $(shell echo headers/*/ | sed -e 's/headers/obj/g')\n\
\n\
#Link main.c with every object\n\
$(TARGET) : $(SOURCES) $(OBJECTS)\n\
\tmkdir -p ./bin\n\
\t$(COMPILER) $(FILENAME) $(wildcard obj/*.o) -o $(TARGET)\n\
\n\
#computes every object from sources\n\
obj/%.o : src/%.c\n\
\tmkdir -p ./obj\n\
\tcd ./obj\n\
\tmkdir -p $(DIRS)\n\
\tcd ../\n\
\t$(COMPILER) -c $^ -o $@\n\
\n\
#Clear eveything and rebuilds it\n\
re : clear $(TARGET)\n\
\n\
#Runs the program\n\
run : $(TARGET)\n\
\t./$(TARGET)\n\
\n\
#Clear workspace of .o files and executable\n\
clear :\n\
\trm -f $(OBJECTS)\n\
\trm -rf ./obj\n\
\trm -f $(TARGET)"

#define MAKEFILE_CPP "COMPILER:= g++\n\
FLAGS := #add flags here. examples : -Wall\n\
\n\
FILENAME := main.cpp\n\
TARGET := bin/main\n\
\n\
# Getting all sources files in src folder\n\
SOURCES = $(shell find src/ -name '*.cpp')\n\
# Converting source files names to objects files\n\
OBJECTS = $(patsubst src/%.cpp, obj/%.o, $(SOURCES))\n\
# Get all dirs\n\
DIRS = $(shell echo headers/*/ | sed -e 's/headers/obj/g')\n\
\n\
#Link main.cpp with every object\n\
$(TARGET) : $(SOURCES) $(OBJECTS)\n\
\tmkdir -p ./bin\n\
\t$(COMPILER) $(FILENAME) $(wildcard obj/*.o) -o $(TARGET)\n\
\n\
#computes every object from sources\n\
obj/%.o : src/%.cpp\n\
\tmkdir -p ./obj\n\
\tcd ./obj\n\
\tmkdir -p $(DIRS)\n\
\tcd ../\n\
\t$(COMPILER) -c $^ -o $@\n\
\n\
#Clear eveything and rebuilds it\n\
re : clear $(TARGET)\n\
\n\
#Runs the program\n\
run : $(TARGET)\n\
\t./$(TARGET)\n\
\n\
#Clear workspace of .o files and executable\n\
clear :\n\
\trm -f $(OBJECTS)\n\
\trm -rf ./obj\n\
\trm -f $(TARGET)"

#define GITIGNORE "bin/\nobj/\ntodo/\ntest/\n.pjm.info"

int newpj(int argc, char *argv[], int language);