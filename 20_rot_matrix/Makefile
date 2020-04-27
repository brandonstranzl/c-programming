CFLAGS=-I -Wall -Werror -pedantic -std=gnu99
CC=gcc

rotate-matrix: read-matrix.o 
	$(CC) -o rotate-matrix read-matrix.o $(CFLAGS) 

read-matrix.o: rotate.c 
	$(CC) -o read-matrix.o -c rotate.c $(CFLAGS)  

