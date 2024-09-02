#include "ArbreBK.h"
#include <ctype.h>

FILE *ouvre_fichier(const char *chemin) {
    FILE *df = fopen(chemin, "r");
    if (df == NULL) {
        fprintf(stderr, "impossible d'ouvrir %s", chemin);
        exit(1);
    }
    return df;
}

void algo_1_et_correction(FILE *f, ArbreBK A){
    Liste corrections;
    char mot[LEN_MAX_MOTS];
    char * tmp;
    corrections = NULL;
    
    while (fscanf(f, "%s ", mot) == 1){
        tmp = mot;
        while(*tmp != '\0'){
            if ('A' <= *tmp && *tmp <= 'Z')
                *tmp = (tolower(*tmp));
            else if (isalpha(*tmp) == 0){
                *tmp = '\0';
                break;
            }
            tmp ++;
        }
        corrections = rechercher_dans_ArbreBK(A, mot);
        if (strcmp(corrections->mot, mot) != 0){
            printf("Mot mal orthographié : %s\nProposition(s) : ", mot);
            afficher_Liste(corrections);
        }
    }
}


int main(int argc, char *argv[]){
    FILE *df2, *df1 ;
    ArbreBK A;
    A = NULL;

    df2 = ouvre_fichier(argv[2]);
    A = creer_ArbreBK(df2);

    printf("\n______MOTS DU DICTIONNAIRE:______\n"); 
    afficher_ArbreBK(A); 

    printf("\n______MOTS CONTENANT DES ERREURS______\n");
    df1 = ouvre_fichier(argv[1]);
    algo_1_et_correction(df1, A);
    fclose(df1);

    fclose(df2);
    liberer_ArbreBK(&A);

    return 0;
}
