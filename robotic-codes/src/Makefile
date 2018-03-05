CFLAG = -lstdc++
CC = clang
NAME = codes

all:
	${CC} atr2.cpp ${CFLAG} -o ${NAME}
	${CC} atrlib.cpp ${CFLAG} -o atrlib.o
	${CC} guilib.cpp ${CFLAG} -o guilib.o
	${CC} robclass.cpp ${CFLAG} -o robclass.o
	${CC} termlib.cpp ${CFLAG} -o termlib.o
clean:
	rm *.out *.o ${NAME}
