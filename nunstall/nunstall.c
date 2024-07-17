#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "nunstall.h"
#include "subcomm.h"
#include "option.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARG_MAX) errorHandler(ERROR_ARG);

    // A dynamic array to know every argument
    arg_t *argFunction;
    // The "argc - 1" is because the first argument
    // is always "nunstall"
    if((argFunction = (arg_t *)calloc(argc - 1, sizeof(arg_t))) == NULL)
        errorHandler(ERROR_MEMORY);

    // Checks what is the function of every argument one by one
    for(uint8_t i = 0; i < argc - 1; i++)
        argFunction[i] = checkArg(argv[i + 1]);

    return 0;
}

// Checks what is the argument passed
arg_t checkArg(const char *arg) {
    // Checks every option
    if(!strcmp(arg, HELP_SUBCOMM1) || !strcmp(arg, HELP_SUBCOMM2))
        return IS_SUBCOMM_HELP;
    
    if(!strcmp(arg, REMOVE_SUBCOMM1) || !strcmp(arg, REMOVE_SUBCOMM2))
        return IS_SUBCOMM_REMOVE;
    
    if(!strcmp(arg, YES_OPTION1) || !strcmp(arg, YES_OPTION2))
        return IS_OPTION_YES;
    
    if(!strcmp(arg, NO_OPTION1) || !strcmp(arg, NO_OPTION2))
        return IS_OPTION_NO;

    return IS_FILE;
}

// Checks what function the program needs
callFunction_t checkFunction(arg_t argFunction[], uint8_t length) {
    // First, checks if the subcomm "help" was used
    for(uint8_t i = 0; i < length; i++)
        if(argFunction[i] == IS_SUBCOMM_HELP) return FUNCTION_HELP;

    
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