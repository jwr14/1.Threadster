/*
Author:  Jason Ronquillo, masc1425
note - stackoverflow.com was used as a resource and there were
some ideas and code used from:
http://stackoverflow.com/questions/16951013/using-semaphore-for-multithreading-in-c
*/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "functions.h" /* header file */


#define READ 'r' /* Opens Existing for Input */
#define NEW 'w' /* Create New/Overwrite for Output */
#define ADD "a" /* Create New/Append for Output */
#define NL '\n' /* ASCII New Line */
#define TAB '\t' /* ASCII Tab */
#define FNAME   "SHARED.txt"
#define NUMBER_OF_THREADS  6

    FILE *fp;
    sem_t SEM;
    
    /* creates SHARED.txt */
    FILE *makeTextFile(char *fname, char mode){
        FILE *localFP = fopen(fname, &mode);
        return (localFP);
    }
    
    /*
    For the even-numbered threads:  
    	in 2-second intervals, calls a down on the semaphore
	opens SHARED.txt and writes the thread ID
	closes SHARED.txt
	calls up, leaving the critical section
	prints to the console a message containing thread id
	this repeats 9 more times
    */
    void *evenPrintMessage(void *tid){ 
    	int i;
    	for (i = 0; i < 10; i++){
	    sleep(2);  /* for 2 second intervals */
            sem_wait(&SEM); /* calls down on semaphore */
            fp = fopen(FNAME, ADD); /* beginning of critical section */
            fprintf(fp, "Thread ID:  %d\r\n", tid);
            fclose(fp); /* end of critical section */
            sem_post(&SEM); /* calls up on semaphore */ 
	    
	    printf("Thread %d is running.\r\n", tid);
    	}	
    }

    /* 
    This function does the exact same thing as the above,
    except in 3-second intervals.
    */
    void *oddPrintMessage(void *tid){
    	int i;
    	for (i = 0; i < 10; i++){
	    sleep(3); /* for 3 second intervals */
            sem_wait(&SEM); /* calls down on semaphore */
            fp = fopen(FNAME, ADD); /* beginning of critical section */
            fprintf(fp, "Thread ID:  %d\r\n", tid);
            fclose(fp); /* end of critical section */
            sem_post(&SEM); /* calls up on semaphore */ 
	    
	    printf("Thread %d is running.\r\n", tid);
    	}	
    }
    
    int threads(){
        const char *fName = "SHARED.txt";
        int status, i;
        pthread_t threads[NUMBER_OF_THREADS];
	
	/* creates 6 threads */
        for (i =0; i < NUMBER_OF_THREADS; i++){
	    if(i==0 || i==2 || i==4) /* if an even-numbered thread... */
            	status = pthread_create(&threads[i], NULL, &evenPrintMessage, (void *)i);	
	    else /* and, for the odd threads */
            	status = pthread_create(&threads[i], NULL, &oddPrintMessage, (void *)i);
            if (status != 0){
                printf("Oops. pthread_create returned error code %d\n", status);
                exit(-1);
                }
            }
	/* joins */
	for(i=0; i<NUMBER_OF_THREADS; i++){
            status = pthread_join(threads[i], NULL);
            if (status != 0){
                printf("Oops. pthread_create returned error code %d\n", status);
                exit(-1);
            }
        }
	    
        return 0;
        
    }
