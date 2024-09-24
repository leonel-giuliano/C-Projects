#ifndef __BT_FILE_H__
#define __BT_FILE_H__


#include <stdio.h>
#include <stdint.h>

#include "bulletin.h"


/* TEXT */

#define PRED_PATH "./bulletin.csv"

#define CONFIG_PATH "./bulletin.config"

// "Students,"
#define STUDENT_ROW_LEN 9


// Counts the ',' from the first line to know the amount of mark names
uint8_t fgetnMarkNames(FILE *_Stream);

// Saves in the 'bulletin.len' the amount of students given the lines of the file
// Returns -1 if the file didn't any data
// Returns 1 if the file didn't have the students names
int8_t fgetnStudents(bulletin_t *_Bulletin);

// Selects the path and opens the file, indicating if it was created
// Returns NULL if there was a problem creating the file
FILE *fopenBt(fpData_t *_FileData);

// Selects the path by the config file or the pred path
// Returns NULL if there was a problem accessing the config file
char *getPath(char *_Buffer);


#endif