#ifndef __NINSTALL_OP_H__
#define __NINSTALL_OP_H__


#include "argop.h"


// Opens the file in the ninstall folder in append mode
// Returns NULL if the home env or file couldn't been open
FILE *fopenProgram(char *_FilePath, const char *_ProgramName);

// Opens the file, creates the comments if neccessarly and opens
// the file with the nano command
FILE *fopenNano(const char *_ProgramName);


/* FLAGS */

void helpFlag();
void versionFlag();


#endif