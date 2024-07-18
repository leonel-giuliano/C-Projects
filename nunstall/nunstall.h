#ifndef __NUNSTALL_H__
#define __NUNSTALL_H__

#include <stdint.h>

// Arguments
#define ARGC_MIN 2
#define ARGC_MAX 4

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

enum {
    IX_COMM,
    IX_SUBCOMM,
    IX_SC_FILE,
    IX_SC_OPTION,

    IX_FILE = 1,
    IX_OPTION
};

// Error events
typedef enum {
    ERROR_ARG
}error_t;

void selectSubcomm(int argc, char *argv[]);
void errorHandler(error_t _ErrorEvent);

#endif