/* This contains the function prototypes used in the corresponding source files for */
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


#define READ 'r' /* Opens Existing for Input */
#define NEW 'w' /* Create New/Overwrite for Output */
#define ADD "a" /* Create New/Append for Output */
#define NL '\n' /* ASCII New Line */
#define TAB '\t' /* ASCII Tab */
#define FNAME   "SHARED.txt"
#define NUMBER_OF_THREADS  6
 
    FILE *makeTextFile(char *fname, char mode);

    void *evenPrintMessage(void *tid);

    void *oddPrintMessage(void *tid);

    int threads();
