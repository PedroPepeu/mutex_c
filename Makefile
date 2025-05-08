# Compiler
CC = gcc
CFLAGS = -Wall -pthread

# Directories
BUILD_DIR = build

# Source files
SRCS = main.c process.c memory.c

# Object files
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

# Output executable
TARGET = program

# Default target
all: $(TARGET)

# Link object files into the final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into build/*.o
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up object files and executable
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
