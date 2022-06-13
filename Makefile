CC = gcc
CFLAGS = -ansi -Wall -pedantic

all: ejecutable

ejecutable: Main.o List.o Pair.o
	$(CC) $(CFLAGS) -o sustituir Main.o List.o Pair.o

Main.o: Main.c
	$(CC) $(CFLAGS) -c Main.c
	
List.o: List.c List.h
	$(CC) $(CFLAGS) -c List.c

Pair.o: Pair.c Pair.h
	$(CC) $(CFLAGS) -c Pair.c

clean:
	rm -rf *.o sustituir