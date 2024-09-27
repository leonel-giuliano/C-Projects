#ifndef __BULLETIN_FILE_H__
#define __BULLETIN_FILE_H__


/* TEXT */

#define PRED_PATH "./bulletin.csv"
#define CONFIG_PATH "./bulletin.config"


// Select the path from the config file or the pred path
// Return NULL if there was a problem reading the config file
char *getPath(char *_Buffer);


#endif