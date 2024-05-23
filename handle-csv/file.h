#include <stdio.h>
#include <stdint.h>

uint8_t getColumns(FILE *_Stream);
// Knows the amounts of columns and returns it
void readRow(char *_Array[], FILE *_Stream);
// Reads every cell from a row