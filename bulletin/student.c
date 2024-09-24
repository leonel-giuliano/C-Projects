#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bulletin.h"
#include "student.h"


uint8_t asknStudents() {
    uint8_t n, loop = 0;
    while(++loop) {
        printf("Amount of students: ");
        scanf("%hhu", &n);

        if(n) return n;

        puts("ERROR: the amount of students can't be 0");
    }

    // If there was a problem in the loop
    return 0;
}


/* ALLOC */

markName_t *mallocMarkName(markName_t *markList) {
    markName_t *mark = (markName_t *)malloc(sizeof(markName_t));

    if(markList == NULL) return markList = mark;

    // Go to the last element in the list
    markName_t *markSeek = markList;
    while(markSeek->next != NULL) markSeek = markSeek->next;

    markSeek->next = mark;
    return mark;
}


void freeMarkNameList(markName_t *markList) {
    if(markList == NULL) return;

    markName_t *markSeek = markList->next;
    while(markSeek != NULL) {
        free(markList);
        markList = markSeek;
        markSeek = markSeek->next;
    }

    free(markList);
}