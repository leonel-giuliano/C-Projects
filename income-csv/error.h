typedef enum {
    ERROR_ARGC,
    ERROR_FILE,
    ERROR_FILE_TYPE
}errorEvent_t;
// All the posible cases of the error

void errorHandler(errorEvent_t _ErrorEvent);