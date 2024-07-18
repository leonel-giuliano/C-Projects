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
#define INSTALL_LINE_N "# Installation\n"
#define UNINSTALL_LINE_N "# Uninstallation\n"


// String chars
#define PATH_MAX 4096
#define TYPE_LENGTH 6
#define INSTALL_LENGTH 15
#define UNINSTALL_LENGTH 17


// Loop limits to prevent errors
#define LOOP_FILE 255
#define LOOP_COMM 255


// Ix of the arguments
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
    ERROR_ARG,
    ERROR_PROGRAM_NOT_FOUND,

    ERROR_DIR,
    ERROR_OPEN_FILE,
    ERROR_RM_FILE,
    ERROR_MEMORY
}error_t;


void selectSubcomm(int argc, char *argv[]);
void errorHandler(error_t _ErrorEvent);


#endif