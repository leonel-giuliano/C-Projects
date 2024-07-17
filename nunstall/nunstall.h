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

// Check for a command inside the call
#define SEARCH_SUBCOMM_HELP(comm) strstr(comm, SPACE_SUBCOMM_HELP1) != NULL || strstr(comm, SPACE_SUBCOMM_HELP2) != NULL
#define SEARCH_SUBCOMM_REMOVE(comm) strstr(comm, SPACE_SUBCOMM_REMOVE1) != NULL || strstr(comm, SPACE_SUBCOMM_REMOVE2) != NULL

#define SEARCH_OPTION_YES(comm) strstr(comm, SPACE_OPTION_YES1) != NULL || strstr(comm, SPACE_OPTION_YES2) != NULL
#define SEARCH_OPTION_NO(comm) strstr(comm, SPACE_OPTION_NO1) != NULL || strstr(comm, SPACE_OPTION_NO2) != NULL

// Compare argument with a command
#define COMP_SUBCOMM_HELP(arg) !strmcp(arg, SUBCOMM_HELP1) || !strmcp(arg, SUBCOMM_HELP2)
#define COMP_SUBCOMM_REMOVE(arg) !strmcp(arg, SUBCOMM_REMOVE1) || !strmcp(arg, SUBCOMM_REMOVE2)

#define COMP_OPTION_YES(arg) !strmcp(arg, OPTION_YES1) || !strmcp(arg, OPTION_YES2)
#define COMP_OPTION_NO(arg) !strmcp(arg, OPTION_NO1) || !strmcp(arg, OPTION_NO2)

// Index of the arguments
enum {
    IX_COMMAND,
    IX_SUBCOMM,
    IX_SM_FILE,
    IX_SM_OPTION,

    IX_FILE = 1,
    IX_OPTION
};

// Posibble function call
typedef enum {
    FUNCTION_HELP,
    FUNCTION_REMOVE,

    FUNCTION_ERROR
}callFunction_t;

// Error events
typedef enum {
    ERROR_ARG,
    ERROR_MEMORY
}errorEvent_t;

callFunction_t checkFunction(uint8_t _ArgumentsNum, char *_Arguments[]);
void errorHandler(errorEvent_t _ErrorEvent);

#endif