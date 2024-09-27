#ifndef __BULLETIN_FILE_H__
#define __BULLETIN_FILE_H__


#include <stdio.h>
#include <stdint.h>

#include "main.h"
#include "bulletin.h"


/* TEXT */

#define PRED_PATH "./bulletin.csv"
#define CONFIG_PATH "./bulletin.config"

#define STUDENTS_COL "Students,"

#define STUDENTS_COL_LEN 9


// Count the amount of rows to know the amount of students
uint8_t fgetnStudents(FILE *_Stream);

// Allocates a mark name in the list and scans the name from the file
// Returns 1 if there was a problem allocating
// Returns -1 if the mark name was empty (',,')
int8_t fgetsMarkNames(bulletin_t *_Bulletin, flags8_t *_Flags);

// Open the file in "r+" or "w+" and checks the flag
// Returns NULL if there was a problem trying to open the file
FILE *fopenBulletin(fpData_t *_FileData, flags8_t *_Flags);

// Select the path from the config file or the pred path
// Return NULL if there was a problem reading the config file
char *getPath(char *_Buffer);


#endif