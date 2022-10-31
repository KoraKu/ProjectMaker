CC := gcc
CC_FLAGS :=

FILENAME := main.c
TARGET := ./bin/main

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))

$(TARGET) : $(FILENAME) $(OBJECTS)
	@echo "Building $(FILENAME)..."
	gcc $(FILENAME) $(OBJECTS) $(CC_FLAGS) -o $(TARGET) 

obj/%.o : src/%.c
	$(CC) -c $^ -o $@

run : $(TARGET)
	@echo "Running $(TARGET) : "
	$(TARGET)

clear :
	rm -f $(TARGET) $(OBJECTS)
