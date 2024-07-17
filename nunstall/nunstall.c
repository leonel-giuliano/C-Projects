#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "nunstall.h"
#include "subcomm.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX)
        errorHandler(ERROR_ARG);

    // Check if the command 'help' is used
    // Ignore argv[0] bc is the command
    for(uint8_t i = 1; i < argc; i++) {
        if(CMP_SUBCOMM(argv[i], IX_SUBCOMM_HELP)) {
            subcommHelp(argv[IX_SUBCOMM]);

            return 0;
        }
    }

    return 0;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of nunstall.\n");
            helpPred();
            break;

        default:
            puts("[DEBUG]: error when used the 'errorHandler'");
            break;
    }

    exit(EXIT_FAILURE);
}