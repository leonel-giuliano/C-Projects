#ifndef __NUNSTALL_H__
#define __NUNSTALL_H__

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

// Error events
typedef enum {
    ERROR_ARG
}errorEvent_t;

void errorHandler(errorEvent_t _ErrorEvent);

#endif