#include "Levenshtein.h"

int min(int a, int b){
    return (a < b) ? a : b;
}
int max(int a, int b){
    return (a > b) ? a : b;
}

int Levenshtein(char * un, char * deux){
    if((min(strlen(un), strlen(deux)) == 0))
        return max(strlen(un), strlen(deux));
    else if(*un == *deux)
        return Levenshtein(un + 1, deux + 1);
    else return 1 + min(min(Levenshtein(un + 1, deux), Levenshtein(un, deux + 1)), Levenshtein(un + 1, deux + 1));
}
