#ifndef __SALES_FILE_H__
#define __SALES_FILE_H__


/* TEXT */

#define PRED_PATH "./sales.csv"

#define CONFIG_PATH "./sales-config.bin"


// Select the pred path or the path inside the config file
// Return NULL if there was a problem trying to read the config file
char *getPath(char *_Buffer);


#endif