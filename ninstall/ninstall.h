#ifndef __NINSTALL_H__
#define __NINSTALL_H__


#include <stdio.h>
#include <stdint.h>

#include "argop.h"


/* ARGUMENTS */

// ninstall [PROGRAM]
#define ARGC_MIN 2

// ninstall remove [PROGRAM] [FLAG] --help
#define ARGC_MAX 5


/* OPERATIONS */

#define OP_AMOUNT 2

#define has_flag argFlags.flags.flag0
#define has_option argFlags.flags.flag1
#define has_flag_rm0 argFlags.flags.flag2
#define has_flag_rm1 argFlags.flags.flag3


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_ARG
};


/* TEXT */

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

#define PRINT_B(str) printf("%s%s%s", BOLD_ON, str, BOLD_OFF);


// Check the arguments operation to initializate 'argFlags' and save
// the type and operation in the '_ArgOp[]'
void initFlags(int argc, char *argv[], argOp_t _ArgOp[]);

// Give an exit failure when is called and print an error msg depending on the event
void errorHandler(error_t _ErrorEvent);


#endif