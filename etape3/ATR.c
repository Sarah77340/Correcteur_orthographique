#include "ATR.h"

ATR creer_ATR_vide(){
    _ATR * a = (_ATR*)malloc(sizeof(_ATR));
    if (a == NULL){
        printf("error allocation\n");
        return NULL;
    }
    a->c = '\0';
    a->fd = NULL;
    a->fg = NULL;
    a->fm = NULL;
    return a;
}

void liberer_ATR(ATR * A){
    if(((*A) -> fg) != NULL)
        liberer_ATR(&((*A)->fg));
    if(((*A) -> fm) != NULL)
        liberer_ATR(&((*A)->fm));
    if(((*A) -> fd) != NULL)
        liberer_ATR(&((*A)->fd));
    free(*A);
    *A = NULL;
}

int ajoute_branche(ATR * A, char * mot){
    if ((*A = creer_ATR_vide()) != NULL){
        (*A)->c = *mot;
        if (*mot != '\0')
            ajoute_branche(&((*A)->fm), mot+1);
        else 
            return 0;
    }
    return 1;
}

int inserer_dans_ATR(ATR *A, char * mot){
    if(*A == NULL)
        return ajoute_branche(A, mot);
        
    else{
        if (*mot < (*A)->c)
            return inserer_dans_ATR(&((*A)->fg), mot);
        else if ((*A)->c == *mot)
            return inserer_dans_ATR(&((*A)->fm), mot + 1);
        else
            return inserer_dans_ATR(&((*A)->fd), mot);
    }
}

void supprimer_dans_ATR(ATR *A, char * mot){
    ATR temp;
    if(*A == NULL)
        return;
    if (*mot < (*A)->c){
        supprimer_dans_ATR(&(*A)->fg, mot);
        return;
    }
    if (*mot > (*A)->c){
        supprimer_dans_ATR(&(*A)->fd, mot);
        return;
    }
    if (*mot == (*A)->c){
        if (*mot == '\0') {
            temp =(*A);
            *A = (*A)->fd;
            free(temp);
            return;
        }
        supprimer_dans_ATR(&(*A)->fm, mot+1);
    }
    if ((*A)->fg == NULL && (*A)->fd == NULL && (*A)->fm == NULL)
        liberer_ATR(A);
}

void affiche_aux(ATR A, char buffer[], int i){
    if (A != NULL){
        buffer[i] = A->c;
        if (A->c == '\0')
            printf("%s \n", buffer);
        else {
            affiche_aux(A->fm, buffer, i+1);
        }
        if (A->fd)
            affiche_aux(A->fd, buffer, i);
        if (A->fg)
            affiche_aux(A->fg, buffer, i);
    }
}

void afficher_ATR(ATR A){
    char buffer[LEN_MAX_MOTS];
    int i = 0;
    affiche_aux(A, buffer, i);
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
    return -1;
}
