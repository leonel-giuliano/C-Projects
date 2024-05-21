#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "main.h"

void errorHandler(errorEvent_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARGC:
            puts("Usage: main.exe (file.csv)[OPTIONAL].");
            break;

        case ERROR_FILE:
            puts("There was a problem with the file.");
            break;

        case ERROR_FILE_TYPE:
            printf("The file isn't a '%s'.\n", FILE_TYPE);
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