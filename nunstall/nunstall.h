#ifndef __NUNSTALL_H__
#define __NUNSTALL_H__

#include <stdint.h>

// Arguments
#define ARGC_MIN 2
#define ARG_MAX 4

// File management
#define PATH_IN_HOME "/ninstall/"
#define FILE_TYPE ".list"
#define INSTALL_LINE "# Installation"
#define UNINSTALL_LINE "# Uninstallation"

// String chars
#define PATH_MAX 4096
#define TYPE_LENGTH 6
#define INSTALL_LENGTH 15
#define UNINSTALL_LENGTH 17

// Argument restrictions
#define MAX_OPTIONS 1       /* Amount of options per call */

#define IX_REMOVE 0
#define IX_NOT_OPTION 0
#define IX_PRED_OPTION 1
#define IX_REMOVE_OPTION 2

// Possible argument pass
typedef enum {
    IS_FILE,

    IS_SUBCOMM_HELP,
    IS_SUBCOMM_REMOVE,

    IS_OPTION_YES,
    IS_OPTION_NO
}arg_t;

// Posibble function call
typedef enum {
    FUNCTION_HELP,
    FUNCTION_REMOVE,
    FUNCTION_REMOVE_YES,
    FUNCTION_REMOVE_NO,

    FUNCTION_ERROR
}callFunction_t;

// Error events
typedef enum {
    ERROR_ARG,
    ERROR_MEMORY
}errorEvent_t;

arg_t checkArg(const char *_Argument);
callFunction_t checkRemove(arg_t _Argument);
callFunction_t checkFunction(arg_t _ArgumentsFunctions[], uint8_t _ArrayLength);
void errorHandler(errorEvent_t _ErrorEvent);

#endif