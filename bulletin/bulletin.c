#include <stdio.h>
#include <stdlib.h>

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

        if(e) return SETUP_MARK_LIST;

        // Read the amount of students in the file
        if(setupFlags.has_students)
            bulletin->len = fgetnStudents(bulletin->fpData.fp, &setupFlags);
    }

    // Ask for the user input if the file was created or if
    // the file didn't have the students
    if(!setupFlags.has_students && !(bulletin->len = getnStudents())) {
        errorHandler(ERROR_INPUT);
        return SETUP_MARK_LIST;
    }

    if((bulletin->students = (student_t *)malloc(bulletin->len * sizeof(student_t))) == NULL) {
        errorHandler(ERROR_NOMEM);
        return SETUP_MARK_LIST;
    }

    return SETUP_NOERROR;
}


uint8_t getnStudents() {
    uint8_t n, loop = 0;

    while(++loop) {
        printf("Amount of students: ");
        scanf("%hhu", &n);

        if(n) return n;

        // In case the input is 0
        puts("ERROR: the amount of students can't be 0");
    }

    return 0;
}


/* ALLOC MARK NAMES */

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
