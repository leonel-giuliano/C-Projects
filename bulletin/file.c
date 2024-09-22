#include <stdio.h>
#include <linux/limits.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "student.h"
#include "file.h"


char *getDir(char *path) {
    FILE *fpConfig = fopen(CONFIG_FILE, "r");

    // Saves the pred path if the config file didn't exist or if
    // there was a problem reading the path
    if(fpConfig == NULL || fgetsClean(path, PATH_MAX, fpConfig) == NULL)
        strncpy(path, PRED_PATH, PATH_MAX);

    if(fpConfig != NULL) fclose(fpConfig);

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


uint8_t fgetsStudents(bulletin_t *bulletin) {
    rewind(bulletin->file);

    // Skip the first line
    char ch;
    while((ch = getc(bulletin->file)) != '\n' && ch != EOF);

    // This shouldn't happen because the 'f_had_names' prevents
    // the program from getting into this function
    if(ch == EOF) return 1;

    // Iterate through evey student
    for(uint8_t i = 0; i < bulletin->len; i++)
        // Reads until the first comma is found
        if(!fscanf(bulletin->file, "%.*[^,]", ST_NAME_MAX, bulletin->students[i].name)) return 1;

    return 0;
}