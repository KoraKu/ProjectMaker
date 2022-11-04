COMPILER:= gcc
FLAGS := -Wall

FILENAME := main.c
TARGET := bin/main

# Getting all sources files in src folder
SOURCES = $(wildcard src/*.c)
# Converting source files names to objects files
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))

#Link main.c with every object
$(TARGET) : $(SOURCES) $(OBJECTS)
	@echo "-> Linking $(FILENAME) with$(OBJECTS) ..."
	@mkdir -p ./bin
	@$(COMPILER) $(FILENAME) $(wildcard obj/*.o) -o $(TARGET)
	@echo "-> Finished building $(TARGET)."

#computes every object from sources
obj/%.o : src/%.c
	@echo "-> Building $^..."
	@mkdir -p ./obj
	@gcc -c $^ -o $@
	

#Clear eveything and rebuilds it
re : clear $(TARGET) 

#Runs the program
run : $(TARGET)
	@echo "-> Executing $(TARGET)."
	@./$(TARGET)

#Clear workspace of .o files and executable
clear :
	@echo "-> Cleaning the workspace ..."
	@rm -f $(OBJECTS)
	@rm -f $(TARGET)
	@echo "-> Removed executables and .o fles."
