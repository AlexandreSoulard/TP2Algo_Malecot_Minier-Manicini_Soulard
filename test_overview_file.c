#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char **argv)
{
  Arbre234 a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv [1]);

  printf ("==== Afficher arbre ====\n") ;

  afficher_arbre (a, 0);
  int h = hauteur(a);
  printf("La hauteur de l'arbre est de :%i\n", h);
  int nb = NombreCles(a);
  printf("Le nombre de clés est de :%i\n", nb);
  int cle_max = CleMax(a);
  printf("La clé max est :%i\n", cle_max);
  int cle_min = CleMin(a);
  printf("La clé min est :%i\n", cle_min);
  Arbre234 b = RechercherCle(a,50);
  printf("=== Afficher sous-arbre dont la racine est la clé cherché : 50 ===\n");
  if (b == NULL){
    printf("Le noeud 50 n'est pas l'arbre\n");
  } else {
    afficher_arbre(b,0);
  }
  printf("\n=== Affichage du noeud max ===\n");
  Arbre234 noeudmax = noeud_max(a);
  afficher_arbre(noeudmax, 0);
  printf("\n=== Affichage des Clés triées dans l'ordre croissant R===");
  Affichage_Cles_Triees_Recursive(a);
  printf("\n=== Affichage des Clés triées dans l'ordre croissant NR===\n");
  Affichage_Cles_Triees_NonRecursive(a);
  printf("=== Affichage des Clés en largeur ===\n");
  Afficher_Cles_Largeur(a);
  printf("=== Affichage du nombre de noeud2/noeud3/noeud4/feuille ===\n");
  int feuille = 0;
  int noeud2 = 0;
  int noeud3 = 0;
  int noeud4 = 0;
  AnalyseStructureArbre(a, &feuille, &noeud2, &noeud3, &noeud4);
  printf("Nombre de feuilles : %i\n", feuille);
  printf("Nombre de noeud2 : %i\n", noeud2);
  printf("Nombre de noeud3 : %i\n", noeud3);
  printf("Nombre de noeud4 : %i\n", noeud4);
}
