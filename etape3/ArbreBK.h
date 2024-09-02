/*Inclusioin de modules*/
#include "Listes.h"
#include "Levenshtein.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define LEN_MAX_MOTS 40

/* Declaration de types */

typedef struct noeudBK{
    char * mot;
    int valeur;
    struct noeudBK * filsG;
    struct noeudBK * frereD;
} NoeudBK, * ArbreBK;

/* Declaration de fonctions */

ArbreBK creer_ArbreBK_vide(char * mot, int valeur);
int inserer_dans_ArbreBK(ArbreBK *A, char * mot);
ArbreBK creer_ArbreBK(FILE * dico);
void afficher_ArbreBK_aux(ArbreBK A, int niveau);
void afficher_ArbreBK(ArbreBK A);
void rechercher_dans_ArbreBK_aux(ArbreBK A, char * m, Liste * corrections, int * seuil);
Liste rechercher_dans_ArbreBK(ArbreBK A, char * mot);
void liberer_ArbreBK(ArbreBK * A);
