#include <stdio.h>
#include <stdint.h>

// CSV
#define FIRST_LINE "#,Name,Type 1,Type 2,Total,HP,Attack,Defense,Sp. Atk,Sp. Def,Speed,Generation,Legendary"
enum {
    COMMA_ID = 1,
    COMMA_NAME,
    COMMA_TYPE_1,
    COMMA_TYPE_2,
    COMMA_TOTAL,
    COMMA_HP,
    COMMA_ATK,
    COMMA_DEF,
    COMMA_SP_ATK,
    COMMA_SP_DEF,
    COMMA_SPEED,
    COMMA_GEN,
    COMMA_LEGENDARY
};
// Parameters

// Pokemon struct
#define NAME_LENGTH 10      /* Electrode */
#define TYPE_AMOUNT 2
#define TYPE_LENGTH 9       /* Electric */
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

pokemon_t *scanPkm(FILE *_Stream);