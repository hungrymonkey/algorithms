CC=gcc
CFLAGS=-Wall -g -std=c99


HEADERS = rtree.h
TEST_SRC = $(wildcard ./test/*.c)
TEST_TARGET = $(TEST_SRC:./test/%.c=%.out)
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

.PHONY: all clean

all: test

t:
	echo $(TEST_SRC)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS)  -c $<  -o $@ 

test: $(TEST_TARGET)

$(TEST_TARGET): %.out:./test/%.c $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $<  -o $@


clean:
	rm -f *.o *.out
