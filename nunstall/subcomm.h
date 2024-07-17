#ifndef __NUNSTALL_SUBCOMM_H__
#define __NUNSTALL_SUBCOMM_H__

// Subcommands
#define SUBCOMM_HELP1 "-h"
#define SUBCOMM_REMOVE1 "-r"

#define SUBCOMM_HELP2 "--help"
#define SUBCOMM_REMOVE2 "--remove"

// Compare str with subcommand
#define CMP_SUBCOMM_HELP(arg) !strcmp(arg, SUBCOMM_HELP1) || !strcmp(arg, SUBCOMM_HELP2)
#define CMP_SUBCOMM_REMOVE(arg) !strcmp(arg, SUBCOMM_REMOVE1) || !strcmp(arg, SUBCOMM_REMOVE2)

void helpPred(void);
void helpRemove(void);
void subcommHelp(const char *_SubCommand);

#endif