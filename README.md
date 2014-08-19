A project with multiple threads - C
====================

multiple threads in C

Author:  Jason Ronquillo

Class info:  CS570 summer 2014

this Filename:  README

Files included:

	- main.c 
	
	- functions.c
	
	- functions.h
	
	- Makefile
	
	- README

Compilation instructions:
	Once inside the correct directory, use the commands (in order):
		% make clean
		% make
		% ./sem

Description:
	The output should consist of printed messages detailing a list of
	threads and the order in which they were serviced - which should be 
	in 2-second intervals for even numbered threads and in 3-second 
	intervals for odd numbered threads.  The process ID and thread ID's 
	are also printed to a file named SHARED.txt, which is created upon 
	running the program.  

Notes on design:
	To facilitate printing messages in 2-second intervals for even threads
	and 3-second intervals for odd threads, I chose to create two separate
	printing functions - one for evens and one for odds.  Upon creation
	of a thread in the threads() function, the threads() function will branch
	to the appropriate printing function depending on if even or odd.  The 
	two printing functions perform identically except that one will perform
	in 2 second intervals and the other in 3 second intervals.  A semaphore
	is used to maintain thread access to the critical sections in both 
	printing functions.

