#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "file.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if(argc != ARGC_PARAM) errorHandler(ERROR_ARGC);
    // Error in case wrong called program

    FILE *fpData;
    if((fpData = fopen(argv[ARGV_FILE], "r+")) == NULL)
        if((fpData = fopen(argv[ARGV_FILE], "w+")) == NULL)
            errorHandler(ERROR_FILE);
    // Uses this instead of appending to change
    // the content already written in the file

    uint8_t columnNum = getColumns(fpData);
    char **columnNames = readRow(columnNum, fpData);
    // Array of the column names

    menuState_t menuState;
    unsigned int loopLimit = 0;
    do {
        menu(&menuState, MENU_ARG);
        loopLimit++;
    }while(menuState != MENU_END && loopLimit != MENU_LOOP);

    freeArrPtr(columnNames, columnNum);
    // Free the pointers within the array and the array itself

    fclose(fpData);

    return 0;
}

void scanstr(char str[], int max, FILE *fp) {
    fgets(str, max, fp);
    // Saves only the amount it can
    // The rest is still in the file

    size_t length = strlen(str);

    if(str[length - 1] != '\n') {
        // Checks if the end of the string is a new line
        char ch;
        while((ch = getc(fp)) != '\n' && ch != EOF);
        // Cleans the data remaining
    } else str[length - 1] = '\0';
    // Replaces the new line with end of a string
}

void freeArrPtr(char **arr, uint8_t length) {
    for(uint8_t i = 0; i < length; i++) free(arr[i]);
    free(arr);
}

void menu(menuState_t *state, MENU_PARAM) {
    void (*menuF[MENU_END])(MENU_PARAM) = {
        menuAdd,
        menuReadRow,
        menuReadCol,
        menuEnd
    };
    // All the functions of the menu

    puts("\n\t-----   MENU   -----");
    printf("%hhu. Add a row.\n", MENU_ADD);
    printf("%hhu. Print a row when inserted the number.\n", MENU_READ_ROW);
    printf("%hhu. Print all the cells of a column.\n", MENU_READ_COL);
    printf("%hhu. Finish the program.\n\n", MENU_END);
    // Options

    printf("Write your option: ");
    scanf(" %u", state);
    while(getchar() != '\n');
    putchar('\n');
    // Scans the option of the menu

    if(*state > MENU_START && *state <= MENU_END)
        menuF[*state - 1](MENU_ARG);
    // Calls the respctive function
    else puts("Choose a given option.");

    putchar('\n');
}

void menuAdd(MENU_PARAM) {
    puts("\n\t-----   ADD ROW   -----");
    addRow(columnNames, columnNum, fpData);
}

void menuReadRow(MENU_PARAM) {
    uint16_t rowNum;
    puts("\n\t-----   READ ROW   -----");
    printf("Insert the position of the row: ");
    scanf(" %hu", &rowNum);
    // Scan the position of the row in hexa

    rewind(fpData);
    char ch;
    uint16_t line = 1;
    while(line != rowNum && (ch = fgetc(fpData)) != EOF)
        if(ch == '\n') line++;
    // Moves the seek where the row is

    char **row = readRow(columnNum, fpData);
    for(uint8_t i = 0; i < columnNum; i++)
        printf("%s: %s\n", columnNames[i], row[i]);
    // Print every cell

    freeArrPtr(row, columnNum);
}

void menuReadCol(MENU_PARAM) {
    uint8_t column;
    puts("\n\t-----   READ COLUMN   -----");
    puts("Insert the column you want to print.");
    // Make col a string and change depending
    // the amount of letters when i > 'Z'
    for(uint8_t i = 0; i < columnNum; i++)
        printf("%s: %c\n", columnNames[i], i + 1);
    // Prints all the options

    printf("\nColumn: ");
    scanf(" %hhu", &column);
    putchar('\n');

    printCol(column, fpData);
}

void menuEnd(MENU_PARAM) {
    puts("Closing program...");

    freeArrPtr(columnNames, columnNum);
    free(columnNames);
    fclose(fpData);
}