#include "ATR.h"
#include "Levenshtein.h"
#include <ctype.h>

FILE *ouvre_fichier(const char *chemin) {
    FILE *df = fopen(chemin, "r");
    if (df == NULL) {
        fprintf(stderr, "impossible d'ouvrir %s", chemin);
        exit(1);
    }
    return df;
}

Liste algo_1(FILE *f, ATR A){
    Liste erreurs;
    char mot[LEN_MAX_MOTS];
    char * tmp;
    int mot_ignore;
    erreurs = NULL;
    
    while (fscanf(f, "%s ", mot) == 1){
        tmp = mot;
        mot_ignore = 0;
        while(*tmp != '\0'){
            if ('A' <= *tmp && *tmp <= 'Z')
                *tmp = (tolower(*tmp));
            else if (isalpha(*tmp) == 0){
                mot_ignore = 1;
                break;
            }
            tmp ++;
        }
        if (mot_ignore == 0){
            if (!appartient_dico(A, mot))
                inserer_en_tete(&erreurs, mot);
        }
    }
    return erreurs;
}

Liste algo_2(FILE * df, char * mot){
    Liste corrections;
    int d, dmin;
    char m[LEN_MAX_MOTS];
    dmin = LEN_MAX_MOTS;
    corrections = NULL;
    rewind(df);
    while (fscanf(df, "%s", m) == 1) {
		d = Levenshtein(m, mot);
        if (d <= dmin){
            if (d < dmin){
                dmin = d;
                if (corrections != NULL)
                    liberer_Liste(&corrections);
            }
            inserer_en_tete(&corrections, m);
        }  
    }
    return corrections;
}

int main(int argc, char *argv[]){
    FILE *df2, *df1 ;
    ATR A;
    Liste L, corrections, tmp;
    A = NULL;
    L = NULL;
    corrections = NULL;
    
    df2 = ouvre_fichier(argv[2]);
    remplir_ATR(df2, &A);
    /*printf("\n______MOTS DU DICTIONNAIRE:______\n");*/
    /*afficher_ATR(A);*/

    df1 = ouvre_fichier(argv[1]);
    L = algo_1(df1, A);
    printf("\n______MOTS CONTENANT DES ERREURS______\n");
    afficher_Liste(L);
    fclose(df1);

    liberer_ATR(&A);

    printf("\n_____________CORRECTIONS______________\n");
    tmp = L;
    while(tmp != NULL){
        printf("\nmot à corriger: %s \n", tmp->mot);
        corrections =  algo_2(df2, tmp->mot);
        printf("corrections proposés :  ");
        afficher_Liste(corrections);
        tmp = tmp -> suivant;
    }    
    
    fclose(df2);
    liberer_Liste(&L);

    return 0;
}
