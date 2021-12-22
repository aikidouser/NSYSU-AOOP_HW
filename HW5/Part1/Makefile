CC = g++
CFLAGS = -ggdb -Wall
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.d)

%.d: %.cpp
	@set -e; \
	rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.Td; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.Td > $@; \
	rm -f $@.Td

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: main

main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f main *.o *.d dep

dep: .dep

.dep:
	$(CC) -M $(SRCS) > dep

include $(OBJS)