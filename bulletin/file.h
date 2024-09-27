#ifndef __BULLETIN_FILE_H__
#define __BULLETIN_FILE_H__


/* TEXT */

#define PRED_PATH "./bulletin.csv"
#define CONFIG_PATH "./bulletin.config"

#define STUDENTS_ROW "Students,"

#define STUDENTS_ROW_LEN 9


#include "main.h"


// Open the file in "r+" or "w+" and checks the flag
// Returns NULL if there was a problem trying to open the file
FILE *fopenBulletin(fpData_t *_FileData, flags8_t *setupFlags);

// Select the path from the config file or the pred path
// Return NULL if there was a problem reading the config file
char *getPath(char *_Buffer);


#endif