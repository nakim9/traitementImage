CC=gcc
FLAGS= -Wall -lm
EXE=exec

all : $(EXE) clean

$(EXE) : main.o BmpLib.o OutilsLib.o image.o fft.o complexUtils.o
	$(CC) -o $@ $^ $(FLAGS)

main.o : main.c
	$(CC) -o $@ -c $< $(FLAGS)

BmpLib.o : BmpLib.c
	$(CC) -o $@ -c $< $(FLAGS)

OutilsLib.o : OutilsLib.c
	$(CC) -o $@ -c $< $(FLAGS)

image.o : image.c
	$(CC) -o $@ -c $< $(FLAGS)

fft.o : fft.c
	$(CC) -o $@ -c $< $(FLAGS)

complexUtils.o : complexUtils.c
	$(CC) -o $@ -c $< $(FLAGS)
	
clean :
	rm -rf *.o
