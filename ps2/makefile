CC = gcc
CFLAGS = -std=c99 -g -pedantic -Wall

life.o: life.c

main.o: main.c

Life: life.o main.o
	${CC} ${CFLAGS}  $^ -o $@

clean:
	rm -f *.o Life