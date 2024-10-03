#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "bulletin.h"
#include "file.h"


setupError_t bulletinSetup(bulletin_t *bulletin) {
    bulletin->len = 0;
    bulletin->markNameList = NULL;
    bulletin->students = NULL;
    bulletin->fpData.fp = NULL;

    if(getPath(bulletin->fpData.path) == NULL) {
        errorHandler(ERROR_FILE, CONFIG_PATH);
        return SETUP_NOGOTO;
    }

    flags8_t setupFlags = { 0 };

    if(fopenBulletin(&bulletin->fpData, &setupFlags) == NULL) {
        errorHandler(ERROR_FILE, bulletin->fpData.path);
        return SETUP_NOGOTO;
    }

    if(setupFlags.was_read) {
        // Read the mark names if the file already existed
        int8_t e = fgetsMarkNames(bulletin, &setupFlags);

        if(e == 1) errorHandler(ERROR_NOMEM);
        else if(e == -1) errorHandler(ERROR_READ_FILE);

        if(e) return SETUP_MARK_NAME_LIST;

        // Read the amount of students in the file
        if(setupFlags.has_students)
            bulletin->len = fgetnStudents(bulletin->fpData.fp, &setupFlags);
    }

    // In case the file was empty
    if(!setupFlags.has_data)
        fprintf(bulletin->fpData.fp, "%s\n", STUDENTS_COL);

    // Ask for the user input if the file was created or if
    // the file didn't have the students
    if(!setupFlags.has_students && !(bulletin->len = getnStudents())) {
        errorHandler(ERROR_INPUT);
        return SETUP_MARK_NAME_LIST;
    }

    if((bulletin->students = (student_t *)malloc(bulletin->len * sizeof(student_t))) == NULL) {
        errorHandler(ERROR_NOMEM);
        return SETUP_MARK_NAME_LIST;
    }

    // Init the markList to NULL
    for(uint8_t i = 0; i < bulletin->len; i++)
        bulletin->students[i].markList = NULL;

    if(setupFlags.has_students) {
        int8_t e = fscanStudents(bulletin);

        if(e == 1) errorHandler(ERROR_NOMEM);
        else if(e == -1) errorHandler(ERROR_READ_FILE);

        if(e) return SETUP_MARK_LIST;
    }
    // If there were no students, asks the user only the names
    else if(getsStudents(bulletin)) {
        errorHandler(ERROR_INPUT);
        return SETUP_STUDENTS;
    }

    return SETUP_NOERROR;
}


uint8_t getsStudents(bulletin_t *bulletin) {
    fseek(bulletin->fpData.fp, 0, SEEK_END);

    for(uint8_t i = 0; i < bulletin->len; i++) {
        printf("Student n°%hhu: ", i + 1);

        char *str = fgetsClean(bulletin->students[i].name, ST_STR_MAX, stdin);
        // In case of some error or the only input is '\n'
        if(str == NULL || !strlen(str)) return 1;

        fprintf(bulletin->fpData.fp, "%s,\n", str);
    }

    return 0;
}


uint8_t getnStudents() {
    uint8_t n, loop = 0;

    while(++loop) {
        printf("Amount of students: ");
        scanf(" %hhu", &n);
        CLEAN_STDIN();

        if(n) return n;

        // In case the input is 0
        puts("ERROR: the amount of students can't be 0");
    }

    return 0;
}


/* ALLOC MARK NAMES */

mark_t *mallocMark(mark_t *mark) {
    mark_t *newMark = (mark_t *)malloc(sizeof(mark_t));
    if(newMark == NULL) return NULL;

    newMark->value = MARK_EMPTY;
    newMark->next = NULL;

    // If the list is empty, it makes it the first element
    if(mark == NULL) return mark = newMark;

    // Goes to the end of the list
    mark_t *markSeek = mark;
    while(markSeek->next != NULL) markSeek = markSeek->next;
    markSeek->next = newMark;

    return newMark;
}


void freeAllMarks(bulletin_t *bulletin) {
    for(uint8_t i = 0; i < bulletin->len; i++)
        freeMarkList(bulletin->students[i].markList);
}


void freeMarkList(mark_t *mark) {
    if(mark == NULL) return;

    // Free from first to last
    mark_t *markSeek = NULL;
    while((markSeek = mark->next) != NULL) {
        free(mark);
        mark = markSeek;
    }

    // Free the last when there is no element left
    free(mark);
}


markName_t *mallocMarkName(markName_t *mark) {
    markName_t *newMark = (markName_t *)malloc(sizeof(markName_t));
    if(newMark == NULL) return NULL;

    newMark->next = NULL;
    // If the list is empty, it makes it the first element
    if(mark == NULL) return mark = newMark;

    // Goes to the end of the list
    markName_t *markSeek = mark;
    while(markSeek->next != NULL) markSeek = markSeek->next;
    markSeek->next = newMark;

    return newMark;
}


void freeMarkNameList(markName_t *mark) {
    if(mark == NULL) return;

    // Free from first to last
    markName_t *markSeek = NULL;
    while((markSeek = mark->next) != NULL) {
        free(mark);
        mark = markSeek;
    }

    // Free the last when there is no element left
    free(mark);
}
