#include <stdio.h>

#include "detect-args.h"


int main(void) {
    const char *comm = {
        "new",
        "edit",
        NULL
    };

    const char *option1 = {
        "-h",
        "-l",
        NULL
    };

    const char *option2 = {
        "--help",
        "--list",
        NULL
    };

    

    return 0;
}