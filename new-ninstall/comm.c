#include <stdint.h>

#include "comm.h"
#include "detect-args.h"
#include "ninstall.h"


// Check Functions

void checkNew(int argc, argOperation_t argOp[]) {
    // Check the amount of arguments
    if(argc < ARG_NEW_MIN || argc > ARG_NEW_MAX) bad_usage = 1;

    // Checks if other operations where passed
    else {
        for(uint8_t i = IX_COMM + 1; i < argc; i++) {
            // The "- 1" is bc of the script command
            if(argOp[i].type != NO_OPERATION) bad_usage = 1;
        }
    }
}

void checkEdit(int argc, argOperation_t argOp[]) {
    // Check the amount of arguments
    if(argc < ARG_EDIT_MIN || argc > ARG_EDIT_MAX) bad_usage = 1;

    // Checks if other operations where passed
    else {
        for(uint8_t i = IX_COMM + 1; i < argc; i++) {
            // The "- 1" is bc of the script command
            if(argOp[i].type != NO_OPERATION) bad_usage = 1;
        }
    }
}

void checkList(int argc, argOperation_t argOp[]) {
    // Check the amount of arguments
    if(argc < ARG_LIST_MIN || argc > ARG_LIST_MAX) bad_usage = 1;

    (void)argOp;
}