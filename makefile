EXE = main
SRC = main.c
OBJ = src/stack.c
CC = gcc
CFLAGS = -g

all: $(EXE)

$(EXE): $(SRC) $(OBJ)
	$(CC) $(SRC) $(OBJ) $(CFLAGS) -o $(EXE)

clean:
	rm -f $(EXE)

.PHONY: clean