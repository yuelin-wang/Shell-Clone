CC = gcc
CFLAGS = -std=c99 -g -D_POSIX_C_SOURCE
BIN = mush
SRCS = mush.c

all: 
	$(CC) $(SRCS) -o $(BIN) $(CFLAGS)
