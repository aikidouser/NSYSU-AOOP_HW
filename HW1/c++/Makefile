CC = g++
CFLAGS = -ggdb -Wall
SRCS = main1.cpp main2.cpp
OBJS = $(SRCS:.cpp=.d)


%.d: %.cpp
	@set -e; \
	rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.Td; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.Td > $@; \
	rm -f $@.Td

all: test1 test2

test1: main1.o stack.o
	$(CC) $(CFLAGS) -o $@ main1.o stack.o $(LIBS)

test2: main2.o stack.o
	$(CC) $(CFLAGS) -o $@ main2.o stack.o $(LIBS)

main1.o: main1.cpp
	$(CC) $(CFLAGS) -c main1.cpp

main2.o: main2.cpp
	$(CC) $(CFLAGS) -c main2.cpp

stack.o: stack.cpp
	$(CC) $(CFLAGS) -c stack.cpp

clean:
	rm -f test1 test2 *.o *.d dep

dep: .dep

.dep: 
	$(CC) -M $(SRCS) > dep

include $(OBJS)