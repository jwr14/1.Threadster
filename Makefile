###########################################################  Makefile
# Summer 2014
# Jason Ronquillo
###########################################################
EXEC = sem
CC = gcc       ###  or use cc / g++ / gcc   ###
FILES = main.c functions.c functions.h
OBJECTS = $(FILES:.c=.o)

$(EXEC):$(OBJECTS) 
	$(CC) -o $(EXEC) $(OBJECTS) -lpthread -lrt
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC)

#######################[ EOF: Makefile ]###################
