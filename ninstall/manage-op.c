#include <stdio.h>
#include <stdint.h>

#include "argop.h"

#include "ninstall.h"
#include "manage-op.h"
#include "op.h"


/* MANAGE */

void manageFlag(int argc, argOp_t argOp[]) {
    flag_t flag;

    // Search for the flag
    for(uint8_t i = 0; i < argc - 1; i++) {
        if(argOp[i].type == TYPE_FLAG) flag = argOp[i].operation;
    }

    // Execute corresponding flag function
    switch(flag) {
        case FLAG_HELP:
            helpFlag();
            break;

        case FLAG_VERSION:
            versionFlag();
            break;
    }
}

void manageOption(int argc, char *argv[], argOp_t argOp[]) {
    // Check if it was used without an option
    option_t op = (has_option) ? argOp[IX_OPTION - 1].operation : OPTION_PRED;

    // Check if the option was used and wasn't in the right index
    if(has_option && op == NOT_FOUND) {
        bad_usage = 1;

        return;
    }

    checkOption(argc, argOp, op);
    if(bad_usage) return;

    selectOption(argc, argv, argOp, op);
}


/* CHECK */

void checkOption(int argc, argOp_t argOp[], option_t op) {
    // For the pred function to align the arguments as it had the option
    argOp_t *pArgOp = argOp;

    void (*checkF)(int, argOp_t []) = NULL;
    switch(op) {
        case OPTION_PRED:
            // This is to call the function like it had the option
            argc++;
            pArgOp--;
            // The following case is the pred. option
            
        // Same check for both
        case OPTION_NEW:
        case OPTION_EDIT:
            checkF = checkNew;
            break;

        case OPTION_LIST:
            checkF = checkList;
            break;

        case OPTION_REMOVE:
            checkF = checkRemove;
            break;
    }

    checkF(argc, pArgOp);
}

void checkNew(int argc, argOp_t argOp[]) {
    if(argc != ARGC_NEW) bad_usage = 1;

    // Check if it is something different from the program
    if(argOp[IX_PROGRAM - 1].type != NOT_FOUND) bad_usage = 1;
}

void checkList(int argc, argOp_t argOp[]) {
    // Doesn't need to be used
    (void)argOp;

    if(argc != ARGC_LIST) bad_usage = 1;
}

void checkRemove(int argc, argOp_t argOp[]) {
    if(argc < ARGC_REMOVE_MIN || argc > ARGC_REMOVE_MAX) bad_usage = 1;

    // Check it is a program
    if(argOp[IX_PROGRAM - 1].type != NOT_FOUND) bad_usage = 1;

    if(argc == ARGC_REMOVE_MAX && argOp[IX_FLAG_RM - 1].type < TYPE_FLAG_RM0)
        bad_usage = 1;
}


/* SELECT */

void selectOption(int argc, char *argv[], argOp_t argOp[], option_t op) {
    // For the pred function
    char **pArgv = argv;

    switch(op) {
        case OPTION_PRED:
            pArgv--;

        case OPTION_NEW:
            newOption(pArgv[IX_PROGRAM]);
            break;

        case OPTION_EDIT:
            editOption(pArgv[IX_PROGRAM]);
            break;

        case OPTION_REMOVE:
            flagRm_t flag = (argc == ARGC_REMOVE_MAX)
                ?   argOp[IX_FLAG_RM - 1].operation
                :   NOT_FOUND;

            removeOption(pArgv[IX_PROGRAM], flag);
            break;
    }
}