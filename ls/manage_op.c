#include <stdio.h>

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