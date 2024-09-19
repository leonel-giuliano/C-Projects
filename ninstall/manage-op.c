#include <stdio.h>
#include <stdint.h>

#include "argop.h"

#include "manage-op.h"


/* MANAGE */

void manageFlag(int argc, argOp_t argOp[]) {
    flag_t flag;

    // Search for the flag
    for(uint8_t i = 0; i < argc - 1; i++) {
        if(argOp[i].type == TYPE_FLAG) flag = argOp[i].operation;
    }

    
}