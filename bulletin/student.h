#ifndef __BT_STUDENT_H__
#define __BT_STUDENT_H__


#include <stdint.h>


/* TEXT */

#define STUDENT_STR_MAX 50

/* STUDENT STRUCT */

typedef struct _mark_t {
    uint8_t value;
    struct _mark_t *next;
} mark_t;

typedef struct {
    char name[STUDENT_STR_MAX];
    mark_t *markList;
} student_t;


#endif