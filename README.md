# Correcteur Orthographique

Projet universitaire de correcteur orthographique basé sur trois étapes :  
1. **Détection des mots mal orthographiés**  
2. **Correction par force brute**  
3. **Utilisation des arbres BK pour l’optimisation**

## Auteurs
- **Manar Nssair**  
- **Nguyen Sarah**  

## Fonctionnalités
Le correcteur orthographique permet de :
- Détecter les mots mal orthographiés en les comparant à un dictionnaire.
- Proposer des corrections en utilisant la distance de Levenshtein.
- Optimiser la recherche avec un **Arbre Ternaire de Recherche (ATR)** et un **Arbre BK**.

## Installation
Assurez-vous d’avoir `gcc` et `make` installés sur votre machine.


## Utilisation
### Étape 1 : Recherche des mots mal orthographiés
```sh
./correcteur_0 fichier_a_corriger.txt dico.dico
```
Ce module détecte les mots absents du dictionnaire.

### Étape 2 : Correction par force brute
```sh
./correcteur_1 fichier_a_corriger.txt dico.dico
```
Ce module utilise l’algorithme de **Levenshtein** pour proposer des corrections.

### Étape 3 : Utilisation des Arbres BK
```sh
./correcteur_2 fichier_a_corriger.txt dico.dico
```
Ce module accélère la recherche des corrections en utilisant un **Arbre BK**.

## Structure du Projet
- `liste.c` / `liste.h` : Gestion des listes chaînées.
- `atr.c` / `atr.h` : Gestion des **Arbres Ternaires de Recherche**.
- `bk_tree.c` / `bk_tree.h` : Gestion des **Arbres BK**.
- `levenshtein.c` : Implémentation de l’algorithme de **Levenshtein**.
- `main.c` : Point d’entrée principal.
