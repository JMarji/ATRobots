CC=g++
CARGS=-lSDL2main -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_mixer
TARGET=rcode

all:
	rm -rf ${TARGET} *.o a.out
	${CC} main.cpp ${CARGS} -o ${TARGET}

clean:
	rm -rf ${TARGET} *.o a.out test

test:
	rm -f test
	${CC} test.cpp ${CARGS} -o test
