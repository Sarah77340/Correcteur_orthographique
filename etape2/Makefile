CC=gcc
CFLAGS=-std=c89 -ansi -pedantic -Wall
SRC=./
EXEC=correcteur_1
 
all: $(EXEC)
 
correcteur_1: $(SRC)correcteur_1.c $(SRC)Listes.o $(SRC)ATR.o $(SRC)Levenshtein.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	
