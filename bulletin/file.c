#include <stdio.h>
#include <linux/limits.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "file.h"


char *getDir(char *path) {
    FILE *fpConfig = fopen(CONFIG_FILE, "r");

    // Saves the pred path if the config file didn't exist or if
    // there was a problem reading the path
    if(fpConfig == NULL || fgetsClean(path, PATH_MAX, fpConfig) == NULL)
        strncpy(path, PRED_PATH, PATH_MAX);

    return path;
}


uint8_t fgetnStudents(FILE *fp) {
    uint8_t n = 0, boolCount = 1;

    char ch;
    while((ch = getc(fp)) != EOF) {
        // Count the first comma
        if(boolCount && ch == ',') {
            boolCount = 0;
            n++;
        }
        
        else if(ch == '\n') boolCount = 1;
    }

    // The first collumn doesn't count
    return --n;
}