#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void errorHandler(errorState_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_FILE:
            puts("There was a problem with the file.");
            break;

        default:
            puts("Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}