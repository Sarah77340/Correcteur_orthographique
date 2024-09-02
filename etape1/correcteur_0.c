#include "ATR.h"
#include <string.h>

FILE *ouvre_fichier(const char *chemin) {
    FILE *df = fopen(chemin, "r");
    if (df == NULL) {
        fprintf(stderr, "impossible d'ouvrir %s", chemin);
        exit(1);
    }
    return df;
}

int remplir_ATR(FILE * df, ATR * A){
    char m[LEN_MAX_MOTS];
    while (fscanf(df, "%s", m) == 1) {
		inserer_dans_ATR(A, m);
    }
    return 0;
}

int appartient_dico(ATR t, char * mot){
    if(t == NULL)
        return 0;
    if(*mot == t -> c){
        if(*mot == '\0')
            return 1;
        else return appartient_dico(t ->fm, mot+1);
    }
    else if(*mot < t -> c)
        return appartient_dico(t -> fg, mot);
    else if(*mot > t -> c)
        return appartient_dico(t -> fd, mot);
}

Liste algo_1(FILE *f, ATR A){
    Liste erreurs;
    char mot[LEN_MAX_MOTS];
    erreurs = NULL;
    
    while (fscanf(f, "%s ", mot) == 1){
        if (!appartient_dico(A, mot))
            inserer_en_tete(&erreurs, mot);
    }
    return erreurs;
}

int main(int argc, char *argv[]){
    FILE *df2, *df1 ;
    ATR A;
    Liste L;
    A = NULL;
    L = NULL;
    
    df2 = ouvre_fichier(argv[2]);
    remplir_ATR(df2, &A);
    printf("\n______MOTS DU DICTIONNAIRE:______\n");
    afficher_ATR(A);
    fclose(df2);

    df1 = ouvre_fichier(argv[1]);
    L = algo_1(df1, A);
    printf("\n______MOTS CONTENANT DES ERREURS:______\n");
    afficher_Liste(L);
    fclose(df1);

    liberer_ATR(&A);
    return 0;
}
