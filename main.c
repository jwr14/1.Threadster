/*
Author:  Jason Ronquillo, masc1425
Assignment #1
CS570, summer '14
*/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "functions.h"


#define READ 'r' /* Opens Existing for Input */
#define NEW 'w' /* Create New/Overwrite for Output */
#define ADD "a" /* Create New/Append for Output */
#define NL '\n' /* ASCII New Line */
#define TAB '\t' /* ASCII Tab */
#define FNAME   "SHARED.txt"
#define NUMBER_OF_THREADS  6

    sem_t SEM;
    
    int main(int argc, char *argv[]){
	
	FILE *fp;
 	char *fName = FNAME;
	
	/* create SHARED.txt in current directory */
 	fp = makeTextFile(fName, NEW); 
	
	/* write it's PID to SHARED.txt, followed by newline */
 	fprintf(fp,"Process ID:  %d\r\n", getpid()); 
	
	/* close the file SHARED.txt */-
 	fclose(fp);
	
	/* initializes the semaphore named SEM to manage access to SHARED.txt */
	sem_init(&SEM, 0, 1);
	
	/* create 6 threads with pthread_create()
		- each thread will periodically get the semaphore
			even numbered - once every two seconds
			odd numbered - once every three seconds
		- each thread will open SHARED.txt and write the TID and newline
		- then print to stdout "Thread <id> is running" and newline
		- close the file SHARED.txt
		- release the semaphore
		- each thread will write to the file and console 10 times
		- exit */
	threads();
	
	/* destroys the semaphore */
	sem_destroy(&SEM);
	
	puts("Thank you!  Please drive through.\n");
	
	return (0);
	
    }//end of main
