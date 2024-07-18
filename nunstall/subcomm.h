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
    IX_SUBCOMM_REMOVE,
    IX_SUBCOMM_PRED = IX_SUBCOMM_REMOVE
};

enum {
    IX_SUBCOMM_1,
    IX_SUBCOMM_2
};

// Compare str with subcommand
#define CMP_SUBCOMM(arg, subcomm) !strcmp(arg, subcommArray[subcomm][IX_SUBCOMM_1]) || !strcmp(arg, subcommArray[subcomm][IX_SUBCOMM_2])

// Subcommands
void subcommHelp(int argc, char *argv[]);
void subcommRemove(int argc, char *argv[]);

// Inside functions of the subcommands
void helpPred(void);
void helpRemove(void);

uint8_t checkRemove(int argc, char *argv[]);

extern const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM];

#endif