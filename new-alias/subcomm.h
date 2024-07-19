#ifndef __NEW_ALIAS_SUBCOMM_H__
#define __NEW_ALIAS_SUBCOMM_H__

// Subcommands array
#define AMOUNT_SUBCOMM 4
#define SAME_SUBCOMM 2

typedef enum {
    IX_SUBCOMM_HELP,
    IX_SUBCOMM_NEW,
    IX_SUBCOMM_REMOVE,
    IX_SUBCOMM_LIST,

    IX_SUBCOMM_PRED = IX_SUBCOMM_NEW
}subcommIx_t;

typedef enum {
    IX_SUBCOMM1,
    IX_SUBCOMM2
}sameSubcommIx_t;


// Subcommands
#define SUBCOMM_HELP1 "-h"
#define SUBCOMM_NEW1 "-n"
#define SUBCOMM_REMOVE1 "-r"
#define SUBCOMM_LIST1 "-l"

#define SUBCOMM_HELP2 "--help"
#define SUBCOMM_NEW2 "--new"
#define SUBCOMM_REMOVE2 "--remove"
#define SUBCOMM_LIST2 "--list"


extern const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM];


// Functions inside the subcommands
void helpPred(void);

#endif