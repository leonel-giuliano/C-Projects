#ifndef __NINSTALL_H__
#define __NINSTALL_H__

// Arguments
#define ARGC_MIN 2
#define ARGC_MAX 3

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

// Loop limit
#define LOOP_INSTALL 255
#define LOOP_LIST 255

enum {
    ARGV_COMM,
    ARGV_SUBCOMM_OR_FILE,
    ARGV_FILE
};

// Enumeration to know the command selected
typedef enum {
    NONE_SELECTED,
    HELP_SELECTED,
    NEW_SELECTED,
    EDIT_SELECTED,
    LIST_SELECTED
}subcommSelected_t;

// All posible errors that exit the code
typedef enum {
    ERROR_ARG,
    ERROR_CALL,
    ERROR_NEW_FILE,
    ERROR_DIR,
    ERROR_MEMORY
}errorEvent_t;

subcommSelected_t checkArg(char *_Argument);
void errorHandler(errorEvent_t _ErrorEvent);

#endif