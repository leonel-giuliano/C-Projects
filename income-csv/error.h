typedef enum {
    ERROR_ARGC,
    ERROR_FILE,
    ERROR_FILE_TYPE,
    ERROR_MALLOC
}errorEvent_t;
// All the posible cases of the error

void errorHandler(errorEvent_t _ErrorEvent);