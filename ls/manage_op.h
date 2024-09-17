#ifndef __LS_MANAGE_H__
#define __LS_MANAGE_H__


#include <stdint.h>


/* MULT OP FLAGS */

// 6 * 8 = 48 flags
#define OP_FLAGS 6

#define has_mult_a opFlags->flags8[0].flags.flag0
#define has_mult_A opFlags->flags8[0].flags.flag1
#define has_mult_b opFlags->flags8[0].flags.flag2
#define has_mult_B opFlags->flags8[0].flags.flag3
#define has_mult_c opFlags->flags8[0].flags.flag4
#define has_mult_C opFlags->flags8[0].flags.flag5
#define has_mult_d opFlags->flags8[0].flags.flag6
#define has_mult_D opFlags->flags8[0].flags.flag7

#define has_mult_f opFlags->flags8[1].flags.flag0
#define has_mult_F opFlags->flags8[1].flags.flag1
#define has_mult_g opFlags->flags8[1].flags.flag2
#define has_mult_G opFlags->flags8[1].flags.flag3
#define has_mult_h opFlags->flags8[1].flags.flag4
#define has_mult_H opFlags->flags8[1].flags.flag5
#define has_mult_i opFlags->flags8[1].flags.flag6
#define has_mult_I opFlags->flags8[1].flags.flag7

#define has_mult_k opFlags->flags8[2].flags.flag0
#define has_mult_l opFlags->flags8[2].flags.flag1
#define has_mult_L opFlags->flags8[2].flags.flag2
#define has_mult_m opFlags->flags8[2].flags.flag3
#define has_mult_n opFlags->flags8[2].flags.flag4
#define has_mult_N opFlags->flags8[2].flags.flag5
#define has_mult_o opFlags->flags8[2].flags.flag6
#define has_mult_p opFlags->flags8[2].flags.flag7

#define has_mult_q opFlags->flags8[3].flags.flag0
#define has_mult_Q opFlags->flags8[3].flags.flag1
#define has_mult_r opFlags->flags8[3].flags.flag2
#define has_mult_R opFlags->flags8[3].flags.flag3
#define has_mult_s opFlags->flags8[3].flags.flag4
#define has_mult_S opFlags->flags8[3].flags.flag5
#define has_mult_t opFlags->flags8[3].flags.flag6
#define has_mult_T opFlags->flags8[3].flags.flag7

#define has_mult_u opFlags->flags8[4].flags.flag0
#define has_mult_U opFlags->flags8[4].flags.flag1
#define has_mult_v opFlags->flags8[4].flags.flag2
#define has_mult_w opFlags->flags8[4].flags.flag3
#define has_mult_x opFlags->flags8[4].flags.flag4
#define has_mult_X opFlags->flags8[4].flags.flag5
#define has_mult_Z opFlags->flags8[4].flags.flag6
#define has_mult_1 opFlags->flags8[4].flags.flag7

#define has_op_author opFlags->flags8[5].flags.flag0
#define has_op_file_type opFlags->flags8[5].flags.flag1
#define has_op_full_time opFlags->flags8[5].flags.flag2
#define has_op_group_dir opFlags->flags8[5].flags.flag3
#define has_op_si opFlags->flags8[5].flags.flag4
#define has_op_dereference opFlags->flags8[5].flags.flag5
#define has_op_show_control opFlags->flags8[5].flags.flag6
#define has_op_zero opFlags->flags8[5].flags.flag7

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
    flags8_t flags8[OP_FLAGS];
} opFlags_t;


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
void checkMult(const char *_MultArg, opFlags_t *opFlags);


#endif