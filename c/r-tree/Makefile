CC=gcc
CFLAGS=-Wall -g -std=c99


HEADERS = rtree.h
TEST_SRC = $(wildcard ./test/*.c)
TEST_TARGET = $(TEST_SRC:./test/%.c=%)
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

.PHONY: all clean

all: test

t:
	echo $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS)  -c $<  -o $@ 

test: $(TEST_SRC) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $<  -o $(patsubst %.c,%.out,$(notdir $<))


clean:
	rm -f *.o *.out
