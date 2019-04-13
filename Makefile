CC=gcc
FLAGS= -Wall
EXE=exec

all : $(EXE) clean

$(EXE) : main.o BmpLib.o OutilsLib.o image.o
	$(CC) -o $@ $^

main.o : main.c BmpLib.h
	$(CC) -o $@ -c $< $(FLAGS)

BmpLib.o : BmpLib.c BmpLib.h
	$(CC) -o $@ -c $< $(FLAGS)

OutilsLib.o : OutilsLib.c OutilsLib.h
	$(CC) -o $@ -c $< $(FLAGS)

image.o : image.c
	$(CC) -o $@ -c $< $(FLAGS)

clean :
	rm -rf *.o
