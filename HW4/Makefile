HELL := /bin/bash
CFLAGS := -g -Wall -std=c++14
CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = $(wildcard *.exe)

ARGS := test1.txt
TEST := main

.PHONY: clean cleanobj cleanall dep main

all: dep main

dep: 
	@touch .depend
	@echo creating dependency file...
	@for n in $(SRC); do \
		$(CC) $(CFLAGS) -E -MM $$n >> .depend; \
	done;
-include .depend

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJ)
	@echo 
	@echo \ \ \ [CC] \ \ \ \  $@
	@$(CC) $(CFLAGS) $(OBJ) -o $@	
	@echo

clean:
	@rm -f .depend res*

cleanobj:
	@rm -f *.o main

cleanall: clean cleanobj
