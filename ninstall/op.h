#ifndef __NINSTALL_OP_H__
#define __NINSTALL_OP_H__


#include <linux/limits.h>
#include <stdint.h>

#include "argop.h"


// Asks the user if it wants to delete the file
// Returns the flag corresponding to the action
flagRm_t askRemove();

// Searches for the comment inside the file and executes
// all of the commands below
// Returns 0 if there was no problem
// Returns 1 if the comment wasn't found
// Returns ENOMEM if there was a problem allocating
uint8_t execCommand(const char *_StrToSearch, FILE *_Stream);

// 'path' gets the value of the directory
// Returns a pointer to only the file path
// Returns NULL if the home env couldn't been open
char *getPath(char *path, const char *program);

// Opens the file, creates the comments if neccessarly and opens
// the file with the nano command
FILE *fopenNano(char *_PathBuffer, const char *_ProgramName);


/* FLAGS */

void helpFlag();
void versionFlag();


/* OPTION */

void newOption(const char *_ProgramName);
void editOption(const char *_ProgramName);
void removeOption(const char *_ProgramName, flagRm_t _Flag);


#endif