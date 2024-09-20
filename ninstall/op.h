#ifndef __NINSTALL_OP_H__
#define __NINSTALL_OP_H__


#include "argop.h"


// Return a pointer to the file in ninstall folder
FILE *openProgram(const char *_ProgramName);


/* FLAGS */

void helpFlag();
void versionFlag();


#endif