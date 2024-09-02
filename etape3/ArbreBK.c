#include "ArbreBK.h"

ArbreBK creer_ArbreBK_vide(char * mot, int valeur){
    NoeudBK * n = (NoeudBK*)malloc(sizeof(NoeudBK));
    if (n == NULL){
        printf("error allocation\n");
        return NULL;
    }
    n->mot = malloc(sizeof(strlen(mot)+1));
    memcpy(n->mot, mot, strlen(mot)+1);
    n->valeur = valeur;
    n->filsG = NULL;
    n->frereD = NULL;
    return n;
}

int inserer_dans_ArbreBK(ArbreBK *A, char * mot){
    NoeudBK * noeud;
    NoeudBK * enfant;
    NoeudBK * new_enfant;
    NoeudBK *  tmp;
    int l;
    if((*A) == NULL){
        *A = creer_ArbreBK_vide(mot, 0);
        return 1;
    }

    noeud = *A ;
    while(1){
        l = Levenshtein(noeud -> mot, mot);
        enfant = noeud->filsG;

        while(enfant){
            if (enfant->valeur == l){
                noeud = enfant;
                break;
            }
            enfant = enfant->frereD;
        }
       
        if (!enfant){
            new_enfant = creer_ArbreBK_vide(mot, l);
            if (!noeud->filsG || noeud->filsG->valeur > l){
                new_enfant->frereD = noeud->filsG;
                noeud->filsG = new_enfant;
                break;
            }
            tmp = noeud->filsG;
            while(tmp->frereD){
                if (tmp->frereD->valeur > l ){
                    break;
                }
                tmp = tmp->frereD;
            }
            new_enfant->frereD = tmp->frereD;
            tmp->frereD = new_enfant;
            break;
        }
    }
    return 0;
}

ArbreBK creer_ArbreBK(FILE * dico){
    ArbreBK a;
    char mot[20];
    a = NULL;
    rewind(dico);
    while(fscanf(dico, "%s", mot) == 1){
        inserer_dans_ArbreBK(&a, mot);
    }
    return a;
}

void afficher_ArbreBK_aux(ArbreBK A, int niveau){
    int i;
    if (A != NULL){
        for (i = 0; i < niveau-1; i++){
            printf("       ");
        }
        if (niveau > 0)
            printf("|-->%d-->", A->valeur);
        printf("%s\n", A->mot);

        if (A->filsG != NULL){
            niveau++;
            afficher_ArbreBK_aux(A->filsG, niveau);
            niveau--;
        }
       
        if (A->frereD != NULL){
            afficher_ArbreBK_aux(A->frereD, niveau);
        }
    }
}

void afficher_ArbreBK(ArbreBK A){
    afficher_ArbreBK_aux(A, 0);
}

void rechercher_dans_ArbreBK_aux(ArbreBK A, char * m, Liste * corrections, int * seuil){
    int d;
    char * u;
    NoeudBK * enfant;
    if(!A){
        return;
    }
    u = A -> mot;
    d = Levenshtein(u, m);
    if(d == *seuil){
        inserer_en_tete(corrections, u);
    }
    if(d < *seuil){
        liberer_Liste(corrections);
        inserer_en_tete(corrections, u);
        *seuil = d;
    }
    enfant = A -> filsG;
    while(enfant){
        if(abs((enfant -> valeur) - d) <= *seuil)
            rechercher_dans_ArbreBK_aux(enfant, m, corrections, seuil);
        enfant = enfant -> frereD;
    }
}

Liste rechercher_dans_ArbreBK(ArbreBK A, char * mot){
    Liste corrections;
    int seuil;
    corrections = NULL;
    seuil = 2;
    rechercher_dans_ArbreBK_aux(A, mot, &corrections, &seuil);
    return corrections;
}

void liberer_ArbreBK(ArbreBK * A){
    if(!A){
        printf("L'arbre est déjà null");
        return;
    }
    if((*A)->filsG){
        liberer_ArbreBK(&((*A)->filsG));
    }
    if((*A)->frereD){
        liberer_ArbreBK(&((*A)->frereD));
    }
    free((*A)->mot);
    free(*A);
    *A = NULL;
}

