CC = g++
CFLAGS = -ggdb -Wall
LIBS = 

all: test1 test2

test1: main1.o stack.o
	${CC} ${CFLAGS} -o $@ main1.o stack.o ${LIBS}

test2: main2.o stack.o
	${CC} ${CFLAGS} -o $@ main2.o stack.o ${LIBS}

main1.o: main1.cpp
	${CC} ${CFLAGS} -c main1.cpp

main2.o: main2.cpp
	${CC} ${CFLAGS} -c main2.cpp

stack.o: stack.cpp
	${CC} ${CFLAGS} -c stack.cpp

clean:
	rm -f test1 test2 *.o 

dep:
	${CC} -MM *.cpp > dep.txt