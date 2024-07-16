#ifndef __NINSTALL_H__
#define __NINSTALL_H__

#define ARGC_MAX 3 /* Max amount of arguments */

// File management
#define PATH_MAX 4096
#define PRED_PATH "~/ninstall"
#define FILE_TYPE ".list"
#define INSTALL_LINE "# Installation"
#define UNINSTALL_LINE "# Uninstallation"

// All posible errors that exit the code
typedef enum {
    ERROR_ARG,
    ERROR_NEW_FILE
}errorEvent_t;

void errorHandler(errorEvent_t _ErrorEvent);

#endif