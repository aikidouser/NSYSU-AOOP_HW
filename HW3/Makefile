CC = g++
CFLAGS = -ggdb -Wall
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.d)


%.d: %.cpp
	@set -e; \
	rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.Td; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.Td > $@; \
	rm -f $@.Td

all: complex

complex: main.o complex.o
	$(CC) $(CFLAGS) -o $@ main.o complex.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

complex.o: complex.cpp
	$(CC) $(CFLAGS) -c complex.cpp

clean:
	rm -f complex *.o *.d dep

dep: .dep

.dep: 
	$(CC) -M $(SRCS) > dep

include $(OBJS)