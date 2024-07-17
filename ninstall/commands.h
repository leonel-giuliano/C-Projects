#ifndef __NINSTALL_COMMANDS_H__
#define __NINSTALL_COMMANDS_H__

// Ninstall commands
#define HELP_COMM1 "-h"
#define NEW_COMM1 "-n"
#define EDIT_COMM1 "-e"
#define LIST_COMM1 "-l"

#define HELP_COMM2 "--help"
#define NEW_COMM2 "--new"
#define EDIT_COMM2 "--edit"
#define LIST_COMM2 "--list"

// Loop limit
#define LOOP_INSTALL 255

void commandHelp(void);
void commandNew(const char *_ProgramName);

#endif