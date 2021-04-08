TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++17 -iquote inc


__START__: ${OBJ} ${OBJ}/main.o ${OBJ}/CKolejka_prio.o ${OBJ}/CKolejka_FIFO.o ${OBJ}/CElement.o ${OBJ}/CSortowanie.o
	g++ -o ${TRGDIR}/kolejka ${OBJ}/main.o ${OBJ}/CKolejka_prio.o ${OBJ}/CKolejka_FIFO.o ${OBJ}/CElement.o ${OBJ}/CSortowanie.o

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/SKolejka_prio.hh inc/SKolejka_FIFO.hh inc/SElement.hh inc/SSortowanie.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/CElement.o:inc/SElement.hh src/CElement.cpp
	g++ -c ${FLAGS} -o ${OBJ}/CElement.o src/CElement.cpp

${OBJ}/CKolejka_prio.o:inc/SKolejka_prio.hh src/SKolejka_prio.cpp src/CKolejka_prio.cpp inc/SElement.hh
	g++ -c ${FLAGS} -o ${OBJ}/CKolejka_prio.o src/CKolejka_prio.cpp

${OBJ}/CKolejka_FIFO.o:inc/SKolejka_FIFO.hh src/SKolejka_FIFO.cpp src/CKolejka_FIFO.cpp inc/SElement.hh
	g++ -c ${FLAGS} -o ${OBJ}/CKolejka_FIFO.o src/CKolejka_FIFO.cpp

${OBJ}/CSortowanie.o:inc/SSortowanie.hh src/CSortowanie.cpp inc/SElement.hh inc/SKolejka_prio.hh inc/SKolejka_FIFO.hh
	g++ -c ${FLAGS} -o ${OBJ}/CSortowanie.o src/CSortowanie.cpp
