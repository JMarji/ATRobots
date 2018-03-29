CC=g++
CARGS=-lSDL2main -lSDL2 -Wall -Wpedantic
TARGET=rcode

all:
	rm -rf ${TARGET} *.o a.out
	${CC} main.cpp ${CARGS} -o ${TARGET}

clean:
	rm -rf ${TARGET} *.o a.out test

test:
	${CC} test.cpp ${CARGS} -o test
