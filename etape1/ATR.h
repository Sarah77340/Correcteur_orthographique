/*Inclusioin de modules*/

#include "Listes.h"

#define LEN_MAX_MOTS 40

/* Declaration de types */

typedef struct _ATR{
    char c;
    struct _ATR *fg, *fm, *fd;
} _ATR, *ATR;

/* Declaration de fonctions */

ATR creer_ATR_vide();
void liberer_ATR(ATR * A);
int ajoute_branche(ATR * A, char * mot);
int inserer_dans_ATR(ATR *A, char * mot);
void supprimer_dans_ATR(ATR *A, char * mot);
void affiche_aux(ATR A, char buffer[], int i);
void afficher_ATR(ATR A);

