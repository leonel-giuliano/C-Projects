#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "nunstall.h"
#include "subcomm.h"
#include "option.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARG_MAX) errorHandler(ERROR_ARG);



    return 0;
}

callFunction_t checkFunction(uint8_t argc, char *argv[]) {
    callFunction_t res = FUNCTION_ERROR;

    // Check if the command "help" was used
    // This ignores a bad usage or other commands
    if(SEARCH_SUBCOMM_HELP(argv[IX_COMMAND]))
        return FUNCTION_HELP;

    // Checks if the subcommand "remove" was used
    // or if there were none subcommand
    if(COMP_SUBCOMM_REMOVE(argv[IX_SUBCOMM]) || argv[IX_FILE][0] != '-')
        res = FUNCTION_REMOVE;

    // Error in case both options are used
    if(SEARCH_OPTION_YES(argv[IX_COMMAND]) && SEARCH_OPTION_NO(argv[IX_COMMAND]))
        res = FUNCTION_ERROR;

    return res;
}

void errorHandler(errorEvent_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the command.\n");
            subcommHelp();
            break;

        case ERROR_MEMORY:
            puts("There was a problem when allocating memory.");
            break;

        default:
            puts("[DEBUG] unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}