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

all: mytar

mytar: main.o mytar.o
	$(CC) $(CFLAGS) -o $@ main.o mytar.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

mytar.o: mytar.cpp
	$(CC) $(CFLAGS) -c mytar.cpp

clean:
	rm -f mytar *.o *.d dep

dep: .dep

.dep: 
	$(CC) -M $(SRCS) > dep

include $(OBJS)