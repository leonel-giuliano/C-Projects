#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void errorHandler(errorEvent_t error) {
    puts("ERROR: ");

    switch(error) {
        case ERROR_ARGC:
            puts("Usage: main.exe [file.csv].");
            break;

        case ERROR_FILE:
            puts("There was a problem with the file.");
            break;

        case ERROR_MALLOC:
            puts("There was a problem allocating.");
            break;

        default:
            puts("Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}