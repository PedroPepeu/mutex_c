# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I.

# Source files and object output
SRC = main.c logic.c
OBJ = $(SRC:%.c=build/%.o)
TARGET = bank_sim

# Default target
all: $(TARGET)

# Link final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ -lpthread

# Compile source files to /build directory
build/%.o: %.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
build:
	mkdir -p build

# Clean build files
clean:
	rm -rf build $(TARGET)

# Phony targets
.PHONY: all clean build
