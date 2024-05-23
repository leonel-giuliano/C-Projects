// Limit for the loops
#define COLUMNS_LOOP 255
#define CH_LOOP 10000

typedef enum {
    ERROR_ARGC,
    ERROR_FILE,
    ERROR_MEMORY
}errorEvent_t;

void errorHandler(errorEvent_t _Error);