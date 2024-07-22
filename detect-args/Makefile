# Define compiler and flags
CC = gcc
CFLAGS = -fpic
LDFLAGS = -shared -Wl,-soname,libdetect-args.so.1

# Source and target files
SRC = libdetect-args.c
OBJ = libdetect-args.o
TARGET = libdetect-args.so.1.0.0

# Default target
all: $(TARGET)

# Compile the source file into an object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the object file into a shared library
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
