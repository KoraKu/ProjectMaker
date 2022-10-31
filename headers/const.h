#ifndef CONST_H
#define CONST_H
#endif

#define C "c"
#define CPP "c++"
#define CPP_ "cpp"

#define PROJECT_FILE ".pjm.info"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define MAKEFILE_C "CC := gcc\n\
CC_FLAGS :=\n\
\n\
FILENAME := main.c\n\
TARGET := ./bin/main\n\
\n\
SOURCES = $(wildcard src/*.c)\n\
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))\n\
\n\
$(TARGET) : $(FILENAME) $(OBJECTS)\n\
\t@echo \"Building $(FILENAME)...\"\n\
\t$(CC) $(FILENAME) $(OBJECTS) $(CC_FLAGS) -o $(TARGET)\n\
\n\
obj/%.o : src/%.c\n\
\t$(CC) -c $^ -o $@\n\
\n\
run : $(TARGET)\n\
\t@echo \"Running $(TARGET) : \"\n\
\t$(TARGET)\n\
\n\
clear :\n\
\trm -f $(TARGET) $(OBJECTS)"

#define MAKEFILE_CPP "CC := g++\n\
CC_FLAGS :=\n\
\n\
FILENAME := main.cpp\n\
TARGET := ./bin/main\n\
\n\
SOURCES = $(wildcard src/*.cpp)\n\
OBJECTS = $(patsubst src/%.cpp, obj/%.o, $(SOURCES))\n\
\n\
$(TARGET) : $(FILENAME) $(OBJECTS)\n\
\t@echo \"Building $(FILENAME)...\"\n\
\t$(CC) $(FILENAME) $(OBJECTS) $(CC_FLAGS) -o $(TARGET)\n\
\n\
obj/%.o : src/%.cpp\n\
\t$(CC) -c $^ -o $@\n\
\n\
run : $(TARGET)\n\
\t@echo \"Running $(TARGET) : \"\n\
\t$(TARGET)\n\
\n\
clear :\n\
\trm -f $(TARGET) $(OBJECTS)"


#define GITIGNORE "bin/\n!bin/info\ntodo/\n.o"