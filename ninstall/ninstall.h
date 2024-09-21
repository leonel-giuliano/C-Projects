#ifndef __NINSTALL_H__
#define __NINSTALL_H__


#include <stdio.h>
#include <stdint.h>

#include "argop.h"


/* ARGUMENTS */

// ninstall [PROGRAM]
#define ARGC_MIN 2
// ninstall new [PROGRAM]
#define ARGC_NEW 3
#define ARGC_EDIT 3
// ninstall list
#define ARGC_LIST 2
// ninstall remove [PROGRAM]
#define ARGC_REMOVE_MIN 3

// ninstall remove [PROGRAM] [FLAG] --help
#define ARGC_MAX 5
// ninstall remove [PROGRAM] [FLAG]
#define ARGC_REMOVE_MAX 4

enum {
    IX_COMM,
    IX_OPTION,
    IX_PROGRAM,
    IX_FLAG_RM,
};


/* OPERATIONS */

#define OP_AMOUNT 4

#define has_flag argFlags.flags.flag0
#define has_option argFlags.flags.flag1
#define has_flag_rm0 argFlags.flags.flag2
#define has_flag_rm1 argFlags.flags.flag3


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_ARG,
    ERROR_COMMENT,
    
    ERROR_FILE,
    ERROR_FCLOSE,
    ERROR_NOMEM,
    ERROR_DIR,
    ERROR_CLOSEDIR
};


/* TEXT */

#define NINSTALL_HOME_FOLDER "ninstall"
#define INSTALL_STR "# Installation\n"
#define UNINSTALL_STR "# Uninstallation\n"

// "nano "
#define NANO_LEN 5
#define COMM_MAX 255

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

#define PRINT_B(str) printf("%s%s%s", BOLD_ON, str, BOLD_OFF);


// Check the arguments operation to initializate 'argFlags' and save
// the type and operation in the '_ArgOp[]'
void initFlags(int argc, char *argv[], argOp_t _ArgOp[]);

// Give an exit failure when is called and print an error msg depending on the event
void errorHandler(errorEvent_t _ErrorEvent, ...);


#endif