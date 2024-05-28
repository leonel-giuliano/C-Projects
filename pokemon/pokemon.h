#include <stdio.h>
#include <stdint.h>

#define PKM_GEN_1 151

// String length
#define NAME_LENGTH 10      /* Electrode */
#define TYPE_LENGTH 9       /* Electric */

// Pokemon struct
#define TYPE_AMOUNT 2
#define GEN_PROGRAM 1
enum {
    IX_TYPE_1,
    IX_TYPE_2
};
// Array index

typedef struct {
    uint8_t lv;
    char name[NAME_LENGTH];
    char type[TYPE_AMOUNT][TYPE_LENGTH];

    uint8_t damage;
    uint8_t defense;
}pokemon_t;

pokemon_t scanPkm(FILE *_Stream);