#include <stdio.h>
#include <stdlib.h>

#include "new-alias.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    return 0;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage of the command.");
            break;

        default:
            perror("[DEBUG] Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}