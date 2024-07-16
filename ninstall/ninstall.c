#include <stdio.h>

#include "ninstall.h"

int main(int argc, char *argv[]) {
    if(argc > ARGC_MAX) errorHandler(ERROR_ARG);
}

void errorHandler(errorEvent_t error) {
    switch(error) {
        case ERROR_ARG:
            break;
    }
}