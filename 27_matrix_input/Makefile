CC=gcc
CFLAGS= -std=gnu99 -pedantic -Wall -c -I

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

rotateMatrix: rotateMatrix.c
	gcc -o rotateMatrix rotateMatrix.c
