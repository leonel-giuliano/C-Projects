#include <stdio.h>
#include <stdlib.h>

#include "nunstall.h"
#include "subcomm.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARG_MAX) errorHandler(ERROR_ARG);

    return 0;    
}

void errorHandler(errorEvent_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the command.\n");
            subcommHelp();
            break;

        default:
            puts("[DEBUG] unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}