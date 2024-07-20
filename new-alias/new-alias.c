#include <stdio.h>
#include <stdlib.h>

#include "new-alias.h"
#include "subcomm.h"

int main (int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    flags_t flags = { 0 };

    // Makes the flags activate depending on the usage
    // and tells which subcommand to use
    subcommIx_t subcomm = checkUsage(argc, argv, &flags);

    // The subcommand "help" has priority
    if(flags.HAS_SUBCOMM_HELP) subcommHelp(subcomm, flags);
    else if(flags.BAD_USAGE) errorHandler(ERROR_ARG);
    else if(!flags.HAS_SUBCOMM) subcommPred(argv);

    // Lastly, all the other subcommands
    else switch(subcomm) {
        case IX_SUBCOMM_NEW:
            subcommNew(argv[IX_SC_ALIAS], argv[IX_SC_CODE]);
            break;

        default:
            errorHandler(ERROR_SUBCOMM);
            break;
    }

    return 0;
}

subcommIx_t checkUsage(int argc, char *argv[], flags_t *flags) {
    // Indicates which subcommand has
    subcommIx_t subcomm = IX_SUBCOMM_PRED;

    // Pointer to function to check which subcomm is
    void (*checkSubcomm[])(int argc, char *argv[], flags_t *flags) = {
        checkNew,
        checkEdit,
        checkRemove,
        checkList
    };

    // Check for the subcommands in the arguments
    for(uint8_t i = IX_COMM + 1; i < argc; i++) {
        for(subcommIx_t j = 0; j < AMOUNT_SUBCOMM; j++) {
            uint8_t boolSubcomm = CMP_SUBCOMM(argv[i], j);

            // In the case the "help" subcommand was used elsewhere
            if(boolSubcomm && j == IX_SUBCOMM_HELP) {
                flags->HAS_SUBCOMM_HELP = 1;

                break;
            }

            // Check the subcommand in the right place
            if(i == IX_SUBCOMM && boolSubcomm) {
                flags->HAS_SUBCOMM = 1;
                subcomm = j;

                break;
            }

            // In the case it found a subcommand elsewhere
            else if(boolSubcomm) {
                flags->BAD_USAGE = 1;

                break;
            }
        }

        // In the case that the subcommand "help" was used,
        // stop checking the other arguments
        if(flags->HAS_SUBCOMM_HELP) break;

        // The subcommand "help" skips all of the checking
        // If there is a bad usage, it keeps checking in the
        // case that the subcommand "help" was used
    }

    // Check the usage depending on the subcommand found
    if(!flags->HAS_SUBCOMM_HELP && !flags->BAD_USAGE)
        checkSubcomm[subcomm - 1](argc, argv, flags);
    // The "- 1" is because the subcommand "help" doesn't need to be checked

    return subcomm;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage.\n");
            helpPred();
            break;

        case ERROR_OPEN_BASH:
            puts("There was a problem when trying to read the bash.");
            break;

        case ERROR_BASH_TEMP:
            puts("There was a problem when trying to create a copy of the bash.");
            break;

        case ERROR_MEMORY:
            puts("There was a problem when allocating.");
            break;

        case ERROR_SUBCOMM:
            puts("[DEBUG] There was a problem trying to choose the subcommand.");
            break;

        default:
            puts("[DEBUG] error in the errorHandler.");
            break;
    }

    exit(EXIT_FAILURE);
}