#include <stdio.h>
#include <stdlib.h>

#include "new-alias.h"
#include "subcomm.h"
#include "option.h"

const char *optionArray[AMOUNT_OPTION][SAME_OPTION] = {
    { OPTION_STATIC1, OPTION_STATIC2 },
    { OPTION_DYNAMIC1, OPTION_DYNAMIC2 }
};

int main (int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    flags_t flags = { 0 };

    // Makes the flags activate depending on the usage
    // and tells which subcommand to use
    uint8_t comm[COMM_FUNCTIONS];
    checkUsage(argc, argv, &flags, comm);

    // Know the offset if there was an option used
    uint8_t offset = (!flags.HAS_OPTION) ? 1 : 0;

    // The subcommand "help" has priority
    if(flags.HAS_SUBCOMM_HELP) subcommHelp(comm[IX_COMM_SUBCOMM], flags);
    else if(flags.BAD_USAGE) errorHandler(ERROR_ARG);
    else if(!flags.HAS_SUBCOMM) subcommPred(argv, comm[IX_COMM_OPTION], flags);

    // Lastly, all the other subcommands
    else switch(comm[IX_COMM_SUBCOMM]) {
        case IX_SUBCOMM_NEW:
            subcommNew(argv[IX_SC_ALIAS], argv[IX_SC_OP_CODE - offset], comm[IX_COMM_OPTION]);
            break;

        case IX_SUBCOMM_EDIT:
            subcommEdit(argv[IX_SC_ALIAS], argv[IX_SC_OP_CODE - offset], comm[IX_COMM_OPTION]);
            break;

        default:
            errorHandler(ERROR_SUBCOMM);
            break;
    }

    return 0;
}

void checkUsage(int argc, char *argv[], flags_t *flags, uint8_t *comm) {
    // To indicate the subcommand and the option
    subcommIx_t subcomm = IX_SUBCOMM_PRED;
    optionIx_t option = IX_OPTION_PRED;

    // Pointer to function to check which subcomm is
    void (*checkSubcomm[])(int argc, flags_t *flags) = {
        checkNew,
        checkEdit,
        checkRemove,
        checkList
    };

    // Check the usage of every argument
    for(uint8_t i = IX_COMM + 1; i < argc; i++) {
        // Check for the subcommands
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

        // Check for the options
        for(optionIx_t j = 0; j < AMOUNT_OPTION; j++) {
            uint8_t boolOption = CMP_OPTION(argv[i], j);
            uint8_t offset = (!flags->HAS_SUBCOMM) ? 1 : 0;

            // Check if the option is in the right position
            if(i == IX_SC_OPTION - offset && boolOption) {
                flags->HAS_OPTION = 1;
                option = j;

                break;
            }

            // Check if it was elsewhere
            else if(boolOption) {
                flags->BAD_USAGE = 1;
                
                break;
            }
        }
    }

    // Check the usage depending on the subcommand found
    if(!flags->HAS_SUBCOMM_HELP && !flags->BAD_USAGE)
        checkSubcomm[subcomm - 1](argc, flags);
    // The "- 1" is because the subcommand "help" doesn't need to be checked

    comm[IX_COMM_SUBCOMM] = subcomm;
    comm[IX_COMM_OPTION] = option;
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