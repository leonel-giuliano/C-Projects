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

void manageOperations(int argc, char *argv[], argOp_t argOp[]) {
    // This flags are used for the final function
    opFlags_t opFlags = { 0 };

    // Check every argument to activate the flags for operation
    for(uint8_t i = 0; i < argc - 1; i++) {
        // Call the respective check function
        switch(argOp[i].type) {
            case TYPE_OPTION:
                // This is to select the index of the char inside 'multOpFlags'
                uint8_t iFlag = argOp[i].operation % sizeof(uint8_t);
                // Made the ix reflect the flag from 0 to 7
                uint8_t ix = argOp[i].operation - iFlag * sizeof(uint8_t);

                opFlags.flags8[iFlag].data |= 1 << ix;
                break;

            case TYPE_MULT:
                checkMult(argv[i + 1], &opFlags);
                break;
        }
    }

    // Iterate through all the arguments in search of the paths
    for(uint8_t i = 1; i < argc; i++) {
        if(argOp[i - 1].type == NOT_FOUND)
            listOp(argv[i], argOp, &opFlags);
    }
}


/* CHECK */

void checkMult(const char *mult, opFlags_t *opFlags) {
    uint8_t len = strlen(mult);

    // Every operation in the flag order
    const char multOp[] = "aAbBcCdDfFgGhHiIklLmnNopqQrRsStTuUvwxXZ1";

    // Compare char by char after the '-'
    for(uint8_t i = 1; i < len; i++) {
        // Pointer to the string from where the char is
        char *str = strchr(multOp, mult[i]);
        // If the char was found, then substracts the pointers to
        // get the index of it
        int8_t ix = (str != NULL) ? (int8_t)(str - multOp) : -1;

        // Activate the flag depending on the order
        if(ix != -1) {
            uint8_t iFlag = ix % sizeof(uint8_t);
            ix -= iFlag * sizeof(uint8_t);

            // Activate the flag by bit
            opFlags->flags8[iFlag].data |= 1 << ix;
        }
    }
}