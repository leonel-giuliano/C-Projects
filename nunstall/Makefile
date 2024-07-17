# Get the last folder name in the path
OUT = $(notdir $(CURDIR))

# Find all .c files in the current directory
SRCS = $(wildcard *.c)

# Generate .o file names from .c file names, prepending the builds directory
OBJS = $(SRCS:%.c=./builds/%.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Default target
all: ./builds/$(OUT)

# Link object files to create the final executable
./builds/$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files to .o files, placing the object files in the builds directory
./builds/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f ./builds/$(OUT) ./builds/*.o

# Phony targets
.PHONY: all clean
