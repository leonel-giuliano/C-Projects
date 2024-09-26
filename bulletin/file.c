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
#include "student.h"


uint8_t fgetsStudents(bulletin_t *bulletin) {
    fseek(bulletin->fpData.fp, STUDENT_ROW_LEN, SEEK_SET);
    char ch;
    while((ch = getc(bulletin->fpData.fp)) != ',' && ch != EOF);

    if(ch == EOF) return 1;

    for(uint8_t i = 0; i < bulletin->len; i++) {
        if(!fscanf(bulletin->fpData.fp, "%.*[^,]", STUDENT_STR_MAX, bulletin->students[i].name)) return 1;

        while((ch = getc(bulletin->fpData.fp)) != ',' && ch != EOF);
    }

    return 0;
}


int8_t fgetsMarkNames(uint8_t n, bulletin_t *bulletin) {
    fseek(bulletin->fpData.fp, STUDENT_ROW_LEN, SEEK_SET);

    markName_t *newMark = NULL;
    for(uint8_t i = 0; i < n; i++) {
        newMark = mallocMarkName(newMark);
        if(newMark == NULL) return 1;

        // The list points to the first element from the list
        if(i == 0) bulletin->markNameList = newMark;

        if(!fscanf(bulletin->fpData.fp, "%.*[^,]", MARK_STR_MAX, newMark->name)) return -1;

        char ch;
        while((ch = getc(bulletin->fpData.fp)) != ',' && ch != EOF);
    }

    return 0;
}


uint8_t fgetnMarkNames(FILE *fp) {
    uint8_t n = 0;

    fseek(fp, STUDENT_ROW_LEN, SEEK_SET);
    char ch;
    while((ch = getc(fp)) != '\n' && ch != EOF) {
        if(ch == ',') n++;
    }

    return n;
}


int8_t fgetnStudents(bulletin_t *bulletin) {
    // Check if the file isn't empty (wasn't created but is empty)
    fseek(bulletin->fpData.fp, 0, SEEK_END);
    if(ftell(bulletin->fpData.fp) < STUDENT_ROW_LEN) return -1;

    // Skip first line
    rewind(bulletin->fpData.fp);
    char ch;
    // Check if the first line has the mark names
    if((ch = getc(bulletin->fpData.fp)) != '\n' && ch != EOF) {
        bulletin->fpData.has_mark_names = 1;

        while((ch = getc(bulletin->fpData.fp)) != '\n' && ch != EOF);
    }

    if(ch == EOF) return 1;

    // Count the lines to know the students amount
    while((ch = getc(bulletin->fpData.fp)) != EOF) {
        if(ch == '\n') bulletin->len++;
    }

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