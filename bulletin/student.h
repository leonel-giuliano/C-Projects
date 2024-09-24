#ifndef __BT_STUDENT_H__
#define __BT_STUDENT_H__


#include <stdint.h>

#include "bulletin.h"


// Asks the user for the amount of students
// Returns 0 only if there was a problem inside the loop
uint8_t asknStudents();


/* ALLOC */

// Allocates a mark name at the end of the list
// Returns NULL if there was a problem allocating
markName_t *mallocMarkName(markName_t *_MarkList);

// Frees all the elements inside the mark name list
void freeMarkNameList(markName_t *_MarkList);


#endif