#include <stdio.h>
#include <stdlib.h>

#include "new-alias.h"

int main (int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage.\n");
            break;

        default:
            puts("[DEBUG] error in the errorHandler.");
            break;
    }

    exit(EXIT_FAILURE);
}