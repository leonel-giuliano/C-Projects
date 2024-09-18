#ifndef __LS_OP_H__
#define __LS_OP_H__


/* FLAG */

void helpFlag();
void versionFlag();


/* OPERATION */

// General function that prints all the info depending on the operations used
void listOp(const char *_DirPath, argOp_t _ArgOp[], opFlags_t *opFlags);


#endif