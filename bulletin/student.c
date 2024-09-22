#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bulletin.h"
#include "student.h"


/* ASK USER INPUT */

uint8_t asknStudents() {
    uint8_t n, loop = 0;

    while(++loop) {
        printf("Amount of students: ");
        scanf("%hhu", &n);

        if(n) return n;    for(uint8_t i = 0; i < n; i++) 

        puts("ERROR: The amounts of students can't be 0"); 
    }

    // In case there is an error (looped over 255 times)
    return 0;
}


uint8_t askNames(bulletin_t *bulletin) {
    // Iterate through every student to scan the name
    for(uint8_t i = 0; i < bulletin->len; i++) {
        printf("Student %hhu: ", i + 1);

        if(fgetsClean(bulletin->students[i].name, ST_NAME_MAX, stdin) == NULL)
            return 1;
    }

    return 0;
}


/* ALLOC */

markName_t *mallocMarkName(markName_t *mark) {
    markName_t *newName = (markName_t *)malloc(sizeof(markName_t));
    if(newName == NULL) return NULL;

    newName->next = NULL;
    if(mark == NULL) return mark = newName;

    // Move to the last element in the list
    markName_t *markSeek = mark;
    while(markSeek->next != NULL) markSeek = markSeek->next;

    markSeek->next = newName;

    return newName;
}


void freeMarkNameList(markName_t *mark) {
    if(mark == NULL) return;

    // Free the list from the start to the end
    while(mark->next != NULL) {
        // So the next doesn't get lost after freeing the mark
        markName_t *markSeek = mark->next;
        free(mark);
        mark = markSeek;
    }

    free(mark);

    return;
}