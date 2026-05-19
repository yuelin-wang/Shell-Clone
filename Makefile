CC = gcc
CFLAGS = -std=c99 -g -D_POSIX_C_SOURCE
BIN = StevenShell
SRCS = StevenShell.c

all: 
	$(CC) $(SRCS) -o $(BIN) $(CFLAGS)
