#ifdef __linux__
    #include <linux/limits.h>
#elif __MINGW32__
    #include <limits.h>
#endif

#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "file.h"


int8_t getnStudents(bulletin_t *bulletin) {
    // Check if the file isn't empty (wasn't created but is empty)
    fseek(bulletin->fpData.fp, 0, SEEK_END);
    if(ftell(bulletin->fpData.fp) < STUDENT_ROW_LEN) return -1;

    // Skip first line
    rewind(bulletin->fpData.fp);
    char ch;
    while((ch = getc(bulletin->fpData.fp)) != '\n' && ch != EOF);
    if(ch == EOF) {
        bulletin->fpData.has_col_names = 1;

        return 1;
    }

    // Count the lines to know the students amount
    while((ch = getc(bulletin->fpData.fp)) != EOF) {
        if(ch == '\n') bulletin->len++;
    }

    bulletin->fpData.has_col_names = 1;
    bulletin->fpData.has_students = 1;

    return 0;
}


FILE *fopenBt(fpData_t *fpData) {
    if((fpData->fp = fopen(fpData->path, "r+")) == NULL) {
        if((fpData->fp = fopen(fpData->path, "w+")) == NULL) return NULL;
    } else fpData->was_read = 1;

    return fpData->fp;
}


char *getPath(char *path) {
    FILE *fpConfig = fopen(CONFIG_PATH, "r");
    // This is when there is a problem accessing the file
    if(fpConfig == NULL && errno != ENOENT) return NULL;

    if(fpConfig == NULL) {
        strncpy(path, PRED_PATH, PATH_MAX);

        return path;
    }

    // If the file exists but there is no path
    if(fgetsClean(path, PATH_MAX, fpConfig) == NULL)
        strncpy(path, PRED_PATH, PATH_MAX);

    fclose(fpConfig);

    return path;
}