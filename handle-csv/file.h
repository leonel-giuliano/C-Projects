#include <stdio.h>
#include <stdint.h>

uint8_t getColumns(FILE*);
// Knows the amounts of columns and returns it
char *readRow(uint8_t _Num, FILE *_Stream);
// Reads every cell from a row