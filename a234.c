#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a234.h"
#include "file.h"

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
  if(a == NULL){
    return 0;
  }
  return a->t-1 + NombreCles(a->fils[0]) + NombreCles(a->fils[1]) + NombreCles(a->fils[2]) + NombreCles(a->fils[4]);
}

int CleMax (Arbre234 a)
{
  if(a == NULL){
    return 0;
  }
  int max = a->cles[0];
  if(a->fils[0] == NULL){
    for(int i = 0; i<a->t-1; i++){
      if(a->cles[i] > max){
        max = a->cles[i];
      }
    }
    return max;
  }
  for(int i = 0; i<a->t; i++){
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
  for(int i = 0; i<a->t-1; i++){
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
  for(int i = 0; i<a->t; i++){
    RechercherCle(a->fils[i], cle);
  }
  return NULL;
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
  for(int i = 0; i<a->t-1; i++){
    if(a->fils[i] == NULL){
      nbfils++;
    }
  }
  if(nbfils == 0){
    *feuilles++;
  }
  for(int i = 0; i<a->t-1;i++){
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

  return NULL;

}


void Afficher_Cles_Largeur (Arbre234 a)
{
	if (a == NULL) return;	//Cas de base, arbre vide
	pfile_t file = creer_file();	//Création d'une pile
	enfiler(file, a);				//Enfilement de la racine
  printf("Création de la file initiale\n");
	while (!file_vide(file)) {		//Parcours en largeur classique
		a = defiler(file);			//Défilement du noeud
    printf("Noeud dépilé\n");
		int nbrFils;
		switch (a->t) {				//Evaluation du type du noeud
		case 0:
			nbrFils = 0;
			break;
		case 2:
			nbrFils = 2;
			break;
		case 3:
			nbrFils = 3;
			break;
		case 4:
			nbrFils = 4;
			break;
		default:
			printf("Error, unknown statement\n");
			break;
		}
		for (int i = 0; i < nbrFils; i++) {
			enfiler(file, a->fils[i]); 	//Puis enfilement de ses fils
		}
		for (int i = 0; i < nbrFils-1; i++) {
			printf("%i ", a->cles[i]);	//Affichage des clés
		}
	}
	printf("\n");
}

void Affichage_Cles_Triees_Recursive (Arbre234 a)
{
  if(a == NULL){
      return;
    }
    if(a->t == 0){
      printf("\n");
      return;
    }
    /*for(int i = 0; i<a->t-1; i++){
      if(nbfils == 0){
       printf("%i ", max);
      }
    }*/
    for(int i = 0; i<a->t; i++){
      Affichage_Cles_Triees_Recursive(a->fils[i]);
      if(i != a->t-1){
        printf("%i", a->cles[i]);
      }
    }
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
  afficher_arbre(b,0);
  Afficher_Cles_Largeur(a);
/*  int* feuille;
  int *noeud2;
  int *noeud3;
  int *noeud4;
  //AnalyseStructureArbre(a, feuille, noeud2, noeud3, noeud4);
  //Affichage_Cles_Triees_Recursive(a);
  printf("%i\n", *feuille);
  printf("%i\n", *noeud2);
  printf("%i\n", *noeud3);
  printf("%i\n", *noeud4);
*/
}
