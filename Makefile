CC=gcc
SRCS=sm4test.c
LIB=sm4
EXEC=sm4test
all:
	$(CC) $(SRCS) -L. -l$(LIB) -o $(EXEC)
