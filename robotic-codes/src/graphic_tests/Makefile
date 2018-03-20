CC=g++
CARGS=-lGL -lGLU -lglfw -lGLEW -lX11 -lXxf86vm -lXrandr -lpthread -lXi
TARGET=test

all:
	rm -rf ${TARGET} *.o a.out
	${CC} main.cpp ${CARGS} -o ${TARGET}

clean:
	rm -rf ${TARGET} *.o a.out
