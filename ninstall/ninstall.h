#ifndef __NINSTALL_H__
#define __NINSTALL_H__

#define ARGC_MAX 3 /* Max amount of arguments */

// File management
#define PATH_IN_HOME "/ninstall/"
#define FILE_TYPE ".list"
#define INSTALL_LINE "# Installation"
#define UNINSTALL_LINE "# Uninstallation"

// String chars
#define PATH_MAX 4096
#define INSTALL_LENGTH 15
#define UNINSTALL_LENGTH 17

// Loop limit
#define LOOP_INSTALL 255

enum {
    ARGV_COMM,
    ARGV_SUBCOMM,
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
    ERROR_NEW_FILE,
    ERROR_MEMORY
}errorEvent_t;

subcommSelected_t checkOption(char *_Subcommand);
void errorHandler(errorEvent_t _ErrorEvent);

#endif