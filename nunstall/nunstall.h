#ifndef __NUNSTALL_H__
#define __NUNSTALL_H__

// Arguments
#define ARGC_MIN 2
#define ARGC_MAX 4

enum {
    IX_COMM,
    IX_SUBCOMM,
    IX_SC_FILE,
    IX_SC_OPTION,

    IX_FILE = 1,
    IX_OPTION
};

// Error events
typedef enum {
    ERROR_ARG
}error_t;

void selectSubComm(char *_ArgumentStr[]);
void errorHandler(error_t _ErrorEvent);

#endif