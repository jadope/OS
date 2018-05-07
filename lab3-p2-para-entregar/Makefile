all: cli clean

CC=gcc
CFLAGS=-I.
DEPS=parser.h ejecutador.h command-table.h
OBJ=parser.o main.o ejecutador.o command-table.o

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

cli: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
