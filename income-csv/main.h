// FILE
#define FILE_PRED "./output/income.csv"
#define FILE_TYPE ".csv"

// ARGUMENTS
enum {
    ARGC_PRED = 1,
    ARGC_FILE
};
enum {
    ARGV_PATH,
    ARGV_FILE
};

char *getPath(int _Argc, char *_Argv[]);
void scanStr(char *_Buffer, size_t _Num, FILE *_Stream);
// Scans a string with a max amount of char