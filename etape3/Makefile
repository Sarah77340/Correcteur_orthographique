CC=gcc
CFLAGS=-std=c89 -ansi -pedantic -Wall
SRC=./
EXEC=correcteur_2
 
all: $(EXEC)
 
correcteur_2: $(SRC)correcteur_2.c $(SRC)Listes.o $(SRC)ArbreBK.o $(SRC)Levenshtein.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	
