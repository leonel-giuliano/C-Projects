#ifndef __NUNSTALL_SUBCOMM_H__
#define __NUNSTALL_SUBCOMM_H__

#include <string.h>

// Info on subcommands
#define AMOUNT_SUBCOMM 2
#define SAME_SUBCOMM 2

// Subcommands
#define SUBCOMM_HELP1 "-h"
#define SUBCOMM_REMOVE1 "-r"

#define SUBCOMM_HELP2 "--help"
#define SUBCOMM_REMOVE2 "--remove"

// Ix subcommands
enum {
    IX_SUBCOMM_HELP,
    IX_SUBCOMM_REMOVE
};

enum {
    IX_SUBCOMM_1,
    IX_SUBCOMM_2
};

// Compare str with subcommand
#define CMP_SUBCOMM(arg, subcomm) !strcmp(arg, subcommArray[subcomm][IX_SUBCOMM_1]) || !strcmp(arg, subcommArray[subcomm][IX_SUBCOMM_2])

// Subcommands
void subcommHelp(const char *_SubCommand);
void subcommRemove(const char *_ProgramName, const char *_Option);

// Inside functions of the subcommands
void helpPred(void);
void helpRemove(void);

extern const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM];

#endif