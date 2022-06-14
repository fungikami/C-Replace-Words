CC = gcc
CFLAGS = -ansi -Wall -pedantic

all: ejecutable

ejecutable: Main.o Lista.o Par.o
	$(CC) $(CFLAGS) -o sustituir Main.o Lista.o Par.o

Main.o: Main.c
	$(CC) $(CFLAGS) -c Main.c
	
Lista.o: Lista.c Lista.h
	$(CC) $(CFLAGS) -c Lista.c

Par.o: Par.c Par.h
	$(CC) $(CFLAGS) -c Par.c

clean:
	rm -rf *.o sustituir