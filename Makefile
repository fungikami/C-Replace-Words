CC = gcc
CFLAGS = -ansi -Wall -pedantic

all: ejecutable

ejecutable: main.o lista.o
	$(CC) $(CFLAGS) -o sustituir main.o lista.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
	
lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

clean:
	rm -rf *.o sustituir