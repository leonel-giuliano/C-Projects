#include <stdint.h>

// CSV
#define FIRST_LINE "#,Name,Type 1,Type 2,Total,HP,Attack,Defense,Sp. Atk,Sp. Def,Speed,Generation,Legendary"
enum {
    ID = 1,
    NAME,
    TYPE_1,
    TYPE_2,
    TOTAL,
    HP,
    ATK,
    DEF,
    SP_ATK,
    SP_DEF,
    SPEED,
    GEN,
    LEGENDARY
};
// Parameters

// Pokemon struct
#define NAME_LENGTH 10      /* Electrode */
#define TYPE_AMOUNT 2
#define TYPE_LENGTH 9       /* Electric */
#define GEN_PROGRAM 1

typedef struct {
    uint8_t lv;
    char name[NAME_LENGTH];

    uint8_t damage;
    uint8_t defense;

    char type[TYPE_AMOUNT][TYPE_LENGTH];
}pokemon_t;

pokemon_t scanPkm(void);