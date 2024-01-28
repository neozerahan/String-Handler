CC = gcc

CFLAG = -Wall -g

EXE = Bin\StringHandler

OBJS = Object\Main Object\StringHelper

$(EXE): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $@

Object\StringHelper: Source\StringHelper.c Header\StringHelper.h
	$(CC) $(CFLAG) -c Source\StringHelper.c -o $@

Object\Main: Source\Main.c Header\StringHelper.h
	$(CC) $(CFLAG) -c Source\Main.c -o $@

clean:
	rm $(OBJS) $(EXE)