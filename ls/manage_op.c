#include <stdio.h>
#include <string.h>

#include "argop.h"

#include "ls.h"
#include "manage_op.h"
#include "op.h"


/* MANAGE */

void manageFlag(int argc, argOp_t argOp[]) {
    flag_t flag;

    // Search which argument is the flag
    for(uint8_t i = 0; i < argc - 1; i++) {
        if(argOp[i].type == TYPE_FLAG) {
            flag = argOp[i].operation;

            break;
        }
    }

    switch(flag) {
        case FLAG_HELP:
            helpFlag();
            break;

        case FLAG_VERSION:
            versionFlag();
            break;
    }
}

void manageOperations(int argc, char argv[], argOp_t argOp[]) {
    // This flags are used for the final function
    multOpFlags_t multOpFlags = { 0 };

    // Check every argument to know the operation
    for(uint8_t i = 0; i < argc - 1; i++) {
        // Call the respective check function
        switch(argOp[i].type) {
            case TYPE_MULT:
                checkMult(argv[i + 1], &multOpFlags);
                break;
        }
    }
}


/* CHECK */

void checkMult(const char *mult, multOpFlags_t *multOpFlags) {
    uint8_t len = strlen(mult);

    // Every operation in the flag order
    const char multOp[] = "aAbBcCdDfFgGhHiIklLmnNopqQrRsStTuUvwxXZ";

    // Compare char by char after the '-'
    for(uint8_t i = 1; i < len; i++) {
        // Pointer to the string from where the char is
        char *str = strchr(multOp, mult[i]);
        // If the char was found, then substracts the pointers to
        // get the index of it
        int8_t ix = (str != NULL) ? str - multOp : -1;

        // Activate the flag depending on the order
        if(ix != -1) {
            // This is to select the index of the char inside 'multOpFlags'
            uint8_t iFlag = ix % sizeof(uint8_t);
            // Made the ix reflect the flag from 0 to 7
            ix -= iFlag * sizeof(uint8_t);

            // Activate the flag by bit
            multOpFlags->flags8[iFlag].data |= 1 << ix;
        }
    }
}