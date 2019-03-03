CC=gcc
CFLAGS=
RM=rm -rf
OUT=main
SRC=src
OBJ=obj

SOURCES=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: build

build: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

	$(OBJ)/%.o: $(SRC)/%.c
	    $(CC) $(CFLAGS) -I$(SRC) -c $< -o $@

	    debug: CFLAGS+=-DDEBUG
	    debug: build

	    .PHONY: clean

	    clean:
	        $(RM) $(OBJ) $(OUT)
