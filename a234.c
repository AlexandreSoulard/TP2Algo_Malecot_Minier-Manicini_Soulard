#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a234.h"

#define max(a,b) ((a)>(b)?(a):(b))


int hauteur (Arbre234 a)
{
  int h0, h1, h2, h3 ;
  
  if (a == NULL)
    return 0 ;

  if (a->t == 0)
    return 0 ;

  h0 = hauteur (a->fils [0]) ;
  h1 = hauteur (a->fils [1]) ;
  h2 = hauteur (a->fils [2]) ;
  h3 = hauteur (a->fils [3]) ;

  return 1 + max (max (h0,h1),max (h2,h3)) ;
} 

int NombreCles (Arbre234 a)
{
  int somme = 0;
  if(a == NULL){
    return 0;
  }
  return somme + a->int - 1 + NombreCles(a->fils[0]) + NombreCles(a->fils[1]) + NombreCles(a->fils[2]) + NombreCles(a->fils[4]);
}

int CleMax (Arbre234 a)
{
  if(a == NULL){
    return 0;
  }
  int max = a->cles[0];
  if(a->fils[0] == NULL){
    for(int i = 0; i<a->t; i++){
      if(a->cles[i] > max){
        max = a->cles[i];
      }
    }
    return max;
  }
  for(int i = 0; i<a->fils.length; i++){
    int n = CleMax(a->fils[i]);
    if(n > max){
      max = n;
    }
  }
  return max;
}

int CleMin (Arbre234 a)
{
  if(a == NULL){
    return 50000;
  }
  int min = a->cles[0];
  if(a->fils[0] == NULL){
    for(int i = 0; i<a->t; i++){
      if(a->cles[i] < min){
        min = a->cles[i];
      }
    }
    return min;
  }
  for(int i = 0; i<a->fils.length; i++){
    int n = CleMin(a->fils[i]);
    if(n < min){
      min = n;
    }
  }
  return min;
}

Arbre234 RechercherCle (Arbre234 a, int cle)
{
  if(a== NULL){
    return NULL;
  }
  for(int i =0; i<a->t; i++){
    if(a->cles[i] == cle){
      return a;
    }
  }
  for(int i = 0; i<a->fils.length; i++){
    return RechercherCle(a->fils[i]);
  }
}

void AnalyseStructureArbre (Arbre234 a, int *feuilles, int *noeud2, int *noeud3, int *noeud4)
{
  if(a == NULL){
    return;
  }
  if(a->t == 2){
    *noeud2++;
  }
  else if(a->t == 3){
    *noeud3++;
  }
  else{
    *noeud4++;
  }
  int nbfils = 0;
  for(int i = 0; i<a->fils.length; i++){
    if(a->fils[i] == NULL){
      nbfils++;
    }
  }
  if(nbfils == 0){
    *feuilles++;
  }
  for(int i = 0; i<a->fils.length;i++){
    AnalyseStructureArbre(a->fils[i], feuilles, noeud2, noeud3, noeud4);
  }
}

Arbre234 noeud_max (Arbre234 a)
{
  int max;
  for(int i = 0; i<a->t; i++){
    max += a->cles[i];
  }
  if(a == NULL){
    return NULL;
  }

  
  return NULL ;
}


void Afficher_Cles_Largeur (Arbre234 a)
{
  /*
    Afficher le cles de l'arbre a avec
    un parcours en largeur
  */

  return ;
}

void Affichage_Cles_Triees_Recursive (Arbre234 a)
{
  /* 
     Afficher les cles en ordre croissant
     Cette fonction sera recursive
  */
     
}

void Affichage_Cles_Triees_NonRecursive (Arbre234 a)
{
    /* 
     Afficher les cles en ordre croissant
     Cette fonction ne sera pas recursive
     Utiliser une pile
  */

}


void Detruire_Cle (Arbre234 *a, int cle)
{
  /*
    retirer la cle de l'arbre a
  */

  return ;
}




int main (int argc, char **argv)
{
  Arbre234 a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv [1]) ;

  printf ("==== Afficher arbre ====\n") ;
  
  afficher_arbre (a, 0) ;

}
