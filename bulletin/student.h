#ifndef __BT_STUDENT_H__
#define __BT_STUDENT_H__


#include <stdint.h>

#include "bulletin.h"


// Scan the students names
// Returns 1 if there was a problem in the input (non char read)
uint8_t scanStudents(bulletin_t *_Bulletin);

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