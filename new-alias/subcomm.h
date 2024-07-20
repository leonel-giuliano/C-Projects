#ifndef __NEW_ALIAS_SUBCOMM_H__
#define __NEW_ALIAS_SUBCOMM_H__

#include <string.h>

// Arguments
#define ARGC_NEW_MIN 4
#define ARGC_EDIT_MIN 4
#define ARGC_REMOVE_MIN 3
#define ARGC_LIST_MIN 2

#define ARGC_NEW_MAX 4
#define ARGC_EDIT_MAX 4
#define ARGC_REMOVE_MAX 3
#define ARGC_LIST_MAX 2

// Subcommands array
#define AMOUNT_SUBCOMM 5
#define SAME_SUBCOMM 2

typedef enum {
    IX_SUBCOMM_HELP,
    IX_SUBCOMM_NEW,
    IX_SUBCOMM_EDIT,
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
#define SUBCOMM_EDIT1 "-e"
#define SUBCOMM_REMOVE1 "-r"
#define SUBCOMM_LIST1 "-l"

#define SUBCOMM_HELP2 "--help"
#define SUBCOMM_NEW2 "--new"
#define SUBCOMM_EDIT2 "--edit"
#define SUBCOMM_REMOVE2 "--remove"
#define SUBCOMM_LIST2 "--list"


// Check if the argument is a subcommand
#define CMP_SUBCOMM(arg, ix_subcomm) !strcmp(arg, subcommArray[ix_subcomm][IX_SUBCOMM1]) || !strcmp(arg, subcommArray[ix_subcomm][IX_SUBCOMM2])


extern const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM];


#include "new-alias.h"

// Check usage per subcommand
void checkNew(int argc, char *argv[], flags_t *flags);
void checkEdit(int argc, char *argv[], flags_t *flags);
void checkRemove(int argc, char *argv[], flags_t *flags);
void checkList(int argc, char *argv[], flags_t *flags);


// Subcommands
void subcommPred(char *argv[]);
void subcommHelp(subcommIx_t _Subcommand, flags_t _Flags);
void subcommNew(const char *_AliasName, const char *_CodeOrPath);


// Functions inside the subcommands
void helpPred(void);
void helpNew(void);
void helpEdit(void);
void helpRemove(void);
void helpList(void);

#endif