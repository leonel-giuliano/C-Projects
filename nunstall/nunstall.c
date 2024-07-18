#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "nunstall.h"
#include "subcomm.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX)
        errorHandler(ERROR_ARG);

    selectSubcomm(argc, argv);

    return 0;
}

void selectSubcomm(int argc, char *argv[]) {
    // A pointer array to the subcommand function depending
    // on the subcommand used
    void (*subcomm[])(int argc, char *argv[]) = {
        subcommHelp,
        subcommRemove
    };

    // Check if the subcommand 'help' was used anywhere in the arguments
    for(uint8_t i = IX_COMM + 1; i < argc; i++) {
        if(CMP_SUBCOMM(argv[IX_SUBCOMM], IX_SUBCOMM_HELP)) {
            subcommHelp(argc, argv);

            exit(EXIT_SUCCESS);
        }
    }

    // Checks if it is a subcomm
    uint8_t boolSubcomm = 0;
    uint8_t ix = 0;
    // Iterate every subcommand to know which one is the argument
    for(uint8_t i = 0; i < AMOUNT_SUBCOMM; i++) {
        if(i == IX_SUBCOMM_HELP) continue;

        if(CMP_SUBCOMM(argv[IX_SUBCOMM], i)) {
            // Save the position of the subcommand 
            ix = i;
            boolSubcomm = 1;
        }
    }

    // Calls the subcommand
    if(boolSubcomm) subcomm[ix](argc, argv);
    // This is in case the subcommand is the pred.
    else if(argv[IX_SUBCOMM][0] != '-') subcomm[IX_SUBCOMM_PRED](argc, argv);
    // If there is an option in the wrong place
    else errorHandler(ERROR_ARG);
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of nunstall.\n");
            helpPred();
            break;

        case ERROR_DIR:
            puts("There was a problem when trying to open the ninstall folder.");
            break;

        case ERROR_PROGRAM_NOT_FOUND:
            puts("The program wasn't found inside the ninstall folder.");
            break;

        case ERROR_FILE:
            puts("There was a problem when trying to open the program file.");
            break;

        case ERROR_MEMORY:
            puts("There was a problem when allocating memory.");
            break;

        default:
            puts("[DEBUG]: error when used the 'errorHandler'");
            break;
    }

    exit(EXIT_FAILURE);
}