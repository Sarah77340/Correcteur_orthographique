/*Inclusioin de modules*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/* Declaration de types */

typedef struct cellule{
    char * mot;
    struct cellule *suivant;
} Cellule, *Liste;

/* Declaration de fonctions */

Cellule * allouer_Cellule(char * mot);
int inserer_en_tete(Liste *L, char * mot);
void afficher_Liste(Liste L);
void liberer_Liste(Liste * L);
