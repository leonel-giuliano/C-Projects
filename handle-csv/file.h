#include <stdio.h>
#include <stdint.h>

uint8_t getColumns(FILE *_Stream);
// Reads the file to know if it has data inside or if
// the file is empty and returns the amount of cells

uint8_t scanColumns(FILE *_Stream);
// In case the file is empty, asks for the names
// and returns the amount of cells

char **readRow(uint8_t _Length, FILE *_Stream);
void addRow(char **_ArrayPtr, uint8_t _Length, FILE *_Stream);
void printCol(uint8_t _Num, FILE *_Stream);