# Nombre del compilador
CC = gcc

# Flags del compilador
CFLAGS = -Wall -Wextra -I.

# Directorios
OUTPUT_DIR = output

# Archivos fuente y objetos
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(OUTPUT_DIR)/%.o, $(SRCS))

# Ejecutable
EXEC = $(OUTPUT_DIR)/main.exe

# Reglas
all: $(OUTPUT_DIR) $(EXEC)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

$(OUTPUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)

.PHONY: all clean
