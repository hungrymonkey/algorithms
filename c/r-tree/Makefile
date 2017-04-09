CC=gcc
CFLAGS=-Wall -g -std=c99


HEADERS = rtree.h
TEST_DIR = ./test/
TEST_SRC = $(wildcard $(TEST_DIR)*.c)
TEST_TARGET = $(TEST_SRC:$(TEST_DIR)%.c=%.out)
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

.PHONY: all clean

all: test

t:
	echo $(TEST_SRC)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS)  -c $<  -o $@ 

test: $(TEST_TARGET)

$(TEST_TARGET): %.out:$(TEST_DIR)%.c $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $<  -o $@


clean:
	rm -f *.o *.out
