#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "main.h"
#include "bulletin.h"
#include "file.h"


uint8_t fscanStudents(bulletin_t *bulletin) {
    // Skip row names
    fseek(bulletin->fpData.fp, STUDENTS_COL_LEN, SEEK_SET);
    char ch;
    while((ch = getc(bulletin->fpData.fp)) != '\n' && ch != EOF);

    uint8_t isFirstMark;
    mark_t *newMark = NULL;

    for(uint8_t i = 0; i < bulletin->len; i++) {
        fgetsCh(bulletin->students[i].name, ST_STR_MAX, ',', bulletin->fpData.fp);

        // Skip the ','
        getc(bulletin->fpData.fp);

        isFirstMark = 1;
        newMark = NULL;

        while((ch = getc(bulletin->fpData.fp)) != '\n' && ch != EOF) {
            ungetc(ch, bulletin->fpData.fp);

            if((newMark = mallocMark(newMark)) == NULL) return 1;

            if(isFirstMark) {
                bulletin->students[i].markList = newMark;
                isFirstMark = 0;
            }

            // If there is a case of ',,' it means the mark wasn't saved yet
            if(!fscanf(bulletin->fpData.fp, "%hhd", &bulletin->students[i].markList->value))
                bulletin->students[i].markList->value = MARK_EMPTY;

            // Skip the ','
            getc(bulletin->fpData.fp);
        }
    }

    return 0;
}


uint8_t fgetnStudents(FILE *fp, flags8_t *flags) {
    uint8_t n = 0;
    fseek(fp, STUDENTS_COL_LEN, SEEK_SET);
    char ch = 0;

    // Repeats per line until the end is found
    while(ch != EOF) {
        // Goes to the end of the line
        while((ch = getc(fp)) != '\n' && ch != EOF);

        n++;
    }

    // Doesn't count the first row;
    if(n-- == 0) flags->has_students = 0;

    return n;
}


int8_t fgetsMarkNames(bulletin_t *bulletin, flags8_t *flags) {
    // Check if the file has a char after the student column len
    fseek(bulletin->fpData.fp, 0, SEEK_END);
    if(ftell(bulletin->fpData.fp) < STUDENTS_COL_LEN + 1) return 0;

    flags->has_data = 1;

    // Check if it has the students column name
    rewind(bulletin->fpData.fp);
    char stCol[STUDENTS_COL_LEN + 1];
    if(strcmp(STUDENTS_COL, fgets(stCol, STUDENTS_COL_LEN + 1, bulletin->fpData.fp))) return 0;

    // Check if the next char to know if there is another mark name
    char ch;
    uint8_t isFirstMark = 1;
    markName_t *mark = NULL;

    while((ch = getc(bulletin->fpData.fp)) != '\n' && ch != ',' && ch != EOF) {
        // 'mark' points to the last element to stay in the end of the list
        if((mark = mallocMarkName(mark)) == NULL) return 1;

        // The list points to the first mark name
        if(isFirstMark) {
            bulletin->markNameList = mark;
            isFirstMark = 0;
        }

        mark->name[0] = ch;
        // Move the name a char because the first one is scanned to check if there was a mark
        fgetsCh(mark->name + 1, MARK_STR_MAX - 1, ',', bulletin->fpData.fp);

        // Skip the ','
        getc(bulletin->fpData.fp);
    }

    // This means there was a ',,' case
    if(ch == ',') return -1;

    if(ch != EOF) flags->has_students = 1;
    flags->has_mark_name = 1;

    return 0;
}


FILE *fopenBulletin(fpData_t *fpData, flags8_t *flags) {
    if((fpData->fp = fopen(fpData->path, "r+")) == NULL) {
        if((fpData->fp = fopen(fpData->path, "w+")) == NULL) return NULL;
    } else flags->was_read = 1;

    return fpData->fp;
}


char *getPath(char *path) {
    FILE *fp = fopen(CONFIG_PATH, "rb");
    if(fp == NULL) {
        // Problem trying to access the config file
        if(errno != ENOENT) return NULL;

        strncpy(path, PRED_PATH, PATH_MAX);
    } else {
        // Read the path byte by byte
        char ch;
        uint16_t i = 0;

        while(i < PATH_MAX && fread(&ch, sizeof(char), 1, fp) && ch != '\0')
            path[i++] = ch;

        if(i) path[i] = '\0';
        // In case there was no data
        else strncpy(path, PRED_PATH, PATH_MAX);

        fclose(fp);
    }

    return path;
}
