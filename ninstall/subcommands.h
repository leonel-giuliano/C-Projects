#ifndef __NINSTALL_SUBCOMMANDS_H__
#define __NINSTALL_SUBCOMMANDS_H__

// Ninstall commands
#define HELP_SUBCOMM1 "-h"
#define NEW_SUBCOMM1 "-n"
#define EDIT_SUBCOMM1 "-e"
#define LIST_SUBCOMM1 "-l"

#define HELP_SUBCOMM2 "--help"
#define NEW_SUBCOMM2 "--new"
#define EDIT_SUBCOMM2 "--edit"
#define LIST_SUBCOMM2 "--list"

FILE *manageFile(const char *_ProgramName, const char *_FileMode);

void subcommHelp(void);
void subcommNew(const char *_ProgramName);
void subcommEdit(const char *_ProgramName);

#endif