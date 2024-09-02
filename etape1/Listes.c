#include "Listes.h"

Cellule * allouer_Cellule(char * mot){
    Cellule *res = malloc(sizeof(Cellule));
    res -> mot = malloc(sizeof(strlen(mot)+1));
    memcpy(res -> mot, mot, strlen(mot)+1);
    res -> suivant = NULL;
    return res;
}

int inserer_en_tete(Liste * L, char * mot){
    Liste c;
    c = allouer_Cellule(mot);
    c->suivant = *L;
    *L = c;
    return 0;
}

void afficher_Liste(Liste L){
    Liste tmp = L;
    while(tmp != NULL){
        printf("%s \n", tmp -> mot);
        tmp = tmp -> suivant;
    }
}

void liberer_Liste(Liste * L){
    if((*L)->suivant != NULL)
        liberer_Liste(&((*L)->suivant));
    free(*L);
    *L = NULL;
}
