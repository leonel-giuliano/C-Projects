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
    for(uint8_t i = 0; i < len; i++) {
    }
}