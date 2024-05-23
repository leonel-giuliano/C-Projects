// Limit for the loops
#define COLUMNS_LOOP 250
#define MENU_LOOP 500

typedef enum {
    ERROR_ARGC,
    ERROR_FILE,
    ERROR_MEMORY
}errorEvent_t;

void errorHandler(errorEvent_t _Error);