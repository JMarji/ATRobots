CFLAG = -lstdc++
CC = g++
NAME = codes

all:
	${CC} atrlib.cpp ${CFLAG} -o atrlib.o
	${CC} errorlogging.cpp ${CFLAG} -o errorlogging.o
	${CC} guilib.cpp ${CFLAG} -o guilib.o
	${CC} init_robot.cpp ${CFLAG} -o init_robot.o
	${CC} robclass.cpp ${CFLAG} -o robclass.o
	${CC} termlib.cpp ${CFLAG} -o termlib.o
	${CC} atr2.cpp ${CFLAG} -o ${NAME}
clean:
	rm -f *.out *.o ${NAME}
