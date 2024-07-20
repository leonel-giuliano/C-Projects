#ifndef __NEW_ALIAS_OPTION_H__
#define __NEW_ALIAS_OPTION_H__

// Options
#define OPTION_STATIC1 "-s"
#define OPTION_DYNAMIC1 "-d"

#define OPTION_STATIC2 "--static"
#define OPTION_DYNAMIC2 "--dynamic"


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

const char *optionArray[AMOUNT_OPTION][SAME_OPTION] = {
    { OPTION_STATIC1, OPTION_STATIC2 },
    { OPTION_DYNAMIC1, OPTION_DYNAMIC2 }
};

extern const char *optionArray[AMOUNT_OPTION][SAME_OPTION];


#endif