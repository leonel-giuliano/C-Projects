#ifndef __NINSTALL_OP_H__
#define __NINSTALL_OP_H__


#include <linux/limits.h>
#include <stdint.h>

#include "argop.h"


#define CATCH_FILE(program, error) {                \
    char path[NAME_MAX];                            \
    snprintf(path, NAME_MAX, "%s.list", program);   \
                                                    \
    errorHandler(error, path);                      \
}


// Searches for the comment inside the file and executes
// all of the commands below
// Returns 0 if there was no problem
// Returns 1 if the comment wasn't found
// Returns ENOMEM if there was a problem allocating
uint8_t execCommand(const char *_StrToSearch, FILE *_Stream);

// Opens the file in the ninstall folder in append mode
// Returns NULL if the home env or file couldn't been open
FILE *fopenProgram(char *_FilePath, const char *_ProgramName);

// Opens the file, creates the comments if neccessarly and opens
// the file with the nano command
FILE *fopenNano(const char *_ProgramName);


/* FLAGS */

void helpFlag();
void versionFlag();


/* OPTION */

void newOption(const char *_ProgramName);


#endif