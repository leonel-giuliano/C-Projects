#ifndef __NEW_ALIAS_OPTION_H__
#define __NEW_ALIAS_OPTION_H__

#include <string.h>

// Options
#define OPTION_STATIC1 "-s"
#define OPTION_DYNAMIC1 "-d"

#define OPTION_STATIC2 "--static"
#define OPTION_DYNAMIC2 "--dynamic"


// Check if the argument is an option
#define CMP_OPTION(arg, optionIx) !strcmp(arg, optionArray[optionIx][IX_OPTION1]) || !strcmp(arg, optionArray[optionIx][IX_OPTION2])


// Options array
#define AMOUNT_OPTION 2
#define SAME_OPTION 2

typedef enum {
    IX_OPTION_STATIC,
    IX_OPTION_DYNAMIC,

    IX_OPTION_PRED = IX_OPTION_STATIC
}optionIx_t;

typedef enum {
    IX_OPTION1,
    IX_OPTION2
}sameOptionIx_t;


#endif