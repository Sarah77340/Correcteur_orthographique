CC=gcc
CFLAGS=-std=c89 -ansi -pedantic -Wall
SRC=./
EXEC=correcteur_0
 
all: $(EXEC)
 
correcteur_0: $(SRC)correcteur_0.c $(SRC)Listes.o $(SRC)ATR.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	
