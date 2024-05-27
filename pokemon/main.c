#include <stdio.h>

#include "pokemon.h"
#include "error.h"

#define PKM_PATH "./pokemon.csv"

int main() {
    FILE *fpPkm;
    if((fpPkm = fopen(PKM_PATH, "r")) == NULL)
        errorHandler(ERROR_FILE);

    return 0;
}