#ifndef __LS_MANAGE_H__
#define __LS_MANAGE_H__


#include <stdint.h>


/* MULT OP FLAGS */

// 5 * 8 = 40 flags (39 options)
#define MULT_FLAGS 5

#define has_mult_a multOpFlags->flags8[0].flags.flag0
#define has_mult_A multOpFlags->flags8[0].flags.flag1
#define has_mult_b multOpFlags->flags8[0].flags.flag2
#define has_mult_B multOpFlags->flags8[0].flags.flag3
#define has_mult_c multOpFlags->flags8[0].flags.flag4
#define has_mult_C multOpFlags->flags8[0].flags.flag5
#define has_mult_d multOpFlags->flags8[0].flags.flag6
#define has_mult_D multOpFlags->flags8[0].flags.flag7

#define has_mult_f multOpFlags->flags8[1].flags.flag0
#define has_mult_F multOpFlags->flags8[1].flags.flag1
#define has_mult_g multOpFlags->flags8[1].flags.flag2
#define has_mult_G multOpFlags->flags8[1].flags.flag3
#define has_mult_h multOpFlags->flags8[1].flags.flag4
#define has_mult_H multOpFlags->flags8[1].flags.flag5
#define has_mult_i multOpFlags->flags8[1].flags.flag6
#define has_mult_I multOpFlags->flags8[1].flags.flag7

#define has_mult_k multOpFlags->flags8[2].flags.flag0
#define has_mult_l multOpFlags->flags8[2].flags.flag1
#define has_mult_L multOpFlags->flags8[2].flags.flag2
#define has_mult_m multOpFlags->flags8[2].flags.flag3
#define has_mult_n multOpFlags->flags8[2].flags.flag4
#define has_mult_N multOpFlags->flags8[2].flags.flag5
#define has_mult_o multOpFlags->flags8[2].flags.flag6
#define has_mult_p multOpFlags->flags8[2].flags.flag7

#define has_mult_q multOpFlags->flags8[3].flags.flag0
#define has_mult_Q multOpFlags->flags8[3].flags.flag1
#define has_mult_r multOpFlags->flags8[3].flags.flag2
#define has_mult_R multOpFlags->flags8[3].flags.flag3
#define has_mult_s multOpFlags->flags8[3].flags.flag4
#define has_mult_S multOpFlags->flags8[3].flags.flag5
#define has_mult_t multOpFlags->flags8[3].flags.flag6
#define has_mult_T multOpFlags->flags8[3].flags.flag7

#define has_mult_u multOpFlags->flags8[4].flags.flag0
#define has_mult_U multOpFlags->flags8[4].flags.flag1
#define has_mult_v multOpFlags->flags8[4].flags.flag2
#define has_mult_w multOpFlags->flags8[4].flags.flag3
#define has_mult_x multOpFlags->flags8[4].flags.flag4
#define has_mult_X multOpFlags->flags8[4].flags.flag5
#define has_mult_Z multOpFlags->flags8[4].flags.flag6

typedef union {
    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    } flags;

    uint8_t data;
} flags8_t;

typedef struct {
    flags8_t flags8[MULT_FLAGS];
} multOpFlags_t;


/* ENUM */

typedef uint8_t flag_t;
enum {
    FLAG_HELP = 1,
    FLAG_VERSION
};


/* MANAGE */

// If there is a flag, this function calls the operation
void manageFlag(int argc, argOp_t _ArgOp[]);

// This manages every other operation apart from the flags
void manageOperations(int argc, char argv[], argOp_t _ArgOp[]);


/* CHECK */

// Checks the flags depending on the operations used
void checkMult(const char *_MultArg, multOpFlags_t *multOpFlags);


#endif