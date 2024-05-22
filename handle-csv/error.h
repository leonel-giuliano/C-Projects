typedef enum {
    ERROR_ARGC,
    ERROR_FILE,
    ERROR_MALLOC
}errorEvent_t;

void errorHandler(errorEvent_t _Error);