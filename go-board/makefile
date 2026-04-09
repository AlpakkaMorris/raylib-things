CC=gcc
INCLUDE_PATH=include
SRC_PATH=src
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all:
	$(CC) src/main.c src/drawing.c -o main -I$(INCLUDE_PATH) $(LIBS) && ./main
# src/params.c src/settings-window.c
