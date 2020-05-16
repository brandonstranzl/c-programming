CC=gcc
CFLAGS= -std=gnu99 -pedantic -Wall -c 
DEPS = power.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test-power: test-power.o power.o
	$(CC) -o test-power test-power.o power.o