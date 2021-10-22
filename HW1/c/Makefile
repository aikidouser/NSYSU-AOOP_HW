CC = gcc
CFLAGS = -ggdb -Wall
SRCS = main1.c main2.c
OBJS = $(SRCS:.c=.d)

%.d: %.c
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

main1.o: main1.c
	$(CC) $(CFLAGS) -c main1.c

main2.o: main2.c
	$(CC) $(CFLAGS) -c main2.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f test1 test2 *.o *.d dep

dep: .dep

.dep: 
	$(CC) -M $(SRCS) > dep

include $(OBJS)