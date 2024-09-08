#include <stdio.h>
#include <stdlib.h>

#include "cat.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    return 0;
}


void errorHandler(error_t error) {
    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the cat function.");
            break;

        default:
            perror("Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}