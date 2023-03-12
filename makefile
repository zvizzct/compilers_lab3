EXE = bottom-up-parsing
SRC = bottom-up-parsing.c
OBJ = src/stack.c src/actionTable.c
CC = gcc
CFLAGS = -g

all: $(EXE)

$(EXE): $(SRC) $(OBJ)
	$(CC) $(SRC) $(OBJ) $(CFLAGS) -o $(EXE)

