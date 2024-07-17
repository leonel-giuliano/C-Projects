#include <stdio.h>
#include <stdlib.h>

#include "nunstall.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX)

    return 0;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of nunstall.\n");
            break;
    }

    exit(EXIT_FAILURE);
}