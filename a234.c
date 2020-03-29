#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a234.h"
#include "file.h"
#include "pile.h"

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
  if(a == NULL || a->t == 0 ){
    return 0;
  }
  return a->t-1 + NombreCles(a->fils[0]) + NombreCles(a->fils[1]) + NombreCles(a->fils[2]) + NombreCles(a->fils[4]);
}

int CleMax (Arbre234 a)
{
  if(a == NULL || a->t == 0){       //Noeud0 ou pas de noeud renvoie aucun max
    return -1;
  }
  int max = 0;
  if (a->t==2 || a->t==3){          //initilisation du max dans les noeud2-3
    max = a->cles[1];
  } else {
    max = a->cles[2];               //initilisation du max dans le cas d'un noeud4
  }

  Arbre234 b = a;

  while (b!=NULL && b->t!=0){       //on parcours les fils droits de l'arbre jusqu'à qu'il n'y ait plus
    if(b->t==2 || b->t==3){
      max = b->cles[1];             //On garde la cles la plus à droite car c'est la plus grande.
      b = b->fils[2];
    } else {
      max = b->cles[2];
      b = b->fils[3];
    }
  }
  return max;
}

int CleMin (Arbre234 a)
{
  if(a == NULL){
    return -1;
  }
  int min = 0;
  if (a->t==2){                     //initialisation du max dans les noeud2
    min = a->cles[1];
  } else if (a->t==3) {             //initilisation du max dans les noeud3
    min = a->cles[0];
  } else {
    min = a->cles[0];               //initilisation du max dans le cas d'un noeud4
  }

  Arbre234 b = a;
  while (b!=NULL && b->t!=0){       //on parcours les fils gauches de l'arbre jusqu'à qu'il n'y ait plus
    if(b->t==2){
      min = b->cles[1];
      b = b->fils[1];
    } else if(b->t==3) {
      min = b->cles[0];             //On garde la cles la plus à gauche car c'est la plus petite.
      b = b->fils[0];
    } else {
      min = b->cles[0];
      b = b->fils[0];
    }
  }
  return min;

}

Arbre234 RechercherCle (Arbre234 a, int cle)
{
  if(a== NULL || a->t==0){
    return NULL;
  }

  if (a->t == 2){
    if (a->cles[1]==cle){
      return a;
    } else {
      Arbre234 res1 = RechercherCle(a->fils[1],cle);
      Arbre234 res2 = RechercherCle(a->fils[2],cle);
      if (res1!= NULL){
        return res1;
      } else if (res2!=NULL){
        return res2;
      } else {
        return res1;
      }
    }
  } else if (a->t==3){
    if (a->cles[0]==cle || a->cles[1]==cle) {
      return a;
    } else {
      Arbre234 res1 = RechercherCle(a->fils[0],cle);
      Arbre234 res2 = RechercherCle(a->fils[1],cle);
      Arbre234 res3 = RechercherCle(a->fils[2],cle);
      if (res1!= NULL){
        return res1;
      } else if (res2!=NULL){
        return res2;
      } else if (res3!=NULL){
        return res3;
      } else {
        return res1;
      }
    }
  } else {
    if (a->cles[0]==cle || a->cles[1]==cle || a->cles[2]==cle){
      return a;
    } else {
      Arbre234 res1 = RechercherCle(a->fils[0],cle);
      Arbre234 res2 = RechercherCle(a->fils[1],cle);
      Arbre234 res3 = RechercherCle(a->fils[2],cle);
      Arbre234 res4 = RechercherCle(a->fils[3],cle);
      if (res1!= NULL){
        return res1;
      } else if (res2!=NULL){
        return res2;
      } else if (res3!=NULL){
        return res3;
      } else if (res4!=NULL){
        return res4;
      } else {
        return res1;
      }
    }
  }
}

void AnalyseStructureArbre (Arbre234 a, int *feuilles, int *noeud2, int *noeud3, int *noeud4)
{
  if(a == NULL){
    return;
  }
  if(a->t == 0){
    return;
  }
  if(a->t == 2){
    *noeud2 = *noeud2 + 1;
  }
  else if(a->t == 3){
    *noeud3 = *noeud3 + 1;
  }
  else if(a->t == 4){
    *noeud4 = *noeud4 + 1;
  }
  int nbfils = 0;
  if(a->t == 2){
    if(a->fils[1]->t != 0){
      nbfils++;
    }
    if(a->fils[2]->t != 0){
      nbfils++;
    }
  }
  else{
    for(int i = 0; i<a->t-1; i++){
      if(a->fils[i]->t != 0){
        nbfils++;
      }
    }
  }
  if(nbfils == 0){
    *feuilles = *feuilles + 1;
  }
  if(a->t == 2){
    AnalyseStructureArbre(a->fils[1], feuilles, noeud2, noeud3, noeud4);
    AnalyseStructureArbre(a->fils[2], feuilles, noeud2, noeud3, noeud4);
  }
  else{
    for(int i = 0; i<a->t;i++){
      AnalyseStructureArbre(a->fils[i], feuilles, noeud2, noeud3, noeud4);
    }
  }
}

int CalculValeurNoeud(Arbre234 a){
  int res = 0;
  if(a->t == 2){
    res += a->cles[1];
  }
  if(a->t == 3){
    res += a->cles[0];
    res += a->cles[1];
  }
  if(a->t == 4){
    res += a->cles[0];
    res += a->cles[1];
    res += a->cles[2];
  }
  return res;
}

Arbre234 noeud_max (Arbre234 a)
{
  pfile_t file = creer_file();
  Arbre234 maximum = a;
  int max = CalculValeurNoeud(maximum);
  enfiler(file, a);
  while (!file_vide(file)) {
    a = defiler(file);
    switch (a->t) {
    case 0:
      break;
    case 2:
      enfiler(file, a->fils[1]);
      enfiler(file, a->fils[2]);
      if(CalculValeurNoeud(a) > max){
        maximum = a;
        max = CalculValeurNoeud(maximum);
      }
      break;
    case 3:
      for (int i = 0; i < 3; i++) {
        enfiler(file, a->fils[i]);
      }
      if(CalculValeurNoeud(a) > max){
        maximum = a;
        max = CalculValeurNoeud(maximum);
      }
      break;
    case 4:
      for (int i = 0; i < 4; i++) {
        enfiler(file, a->fils[i]);
      }
      if(CalculValeurNoeud(a) > max){
        maximum = a;
        max = CalculValeurNoeud(maximum);
      }
      break;
    default:
      printf("Error, unknown statement\n");
      break;
    }
  }
  return maximum;
}


void Afficher_Cles_Largeur (Arbre234 a)
{
	if (a == NULL) return;			//Cas de base, arbre vide
	pfile_t file = creer_file();	//Création d'une pile
	enfiler(file, a);				//Enfilement de la racine*
	while (!file_vide(file)) {		//Parcours en largeur classique
		a = defiler(file);			//Défilement/récupération du noeud

		switch (a->t) {						//Evaluation du type du noeud
		case 0:								//Arbre de type 0, il n'y a rien à afficher
			break;
		case 2:								//Arbre de type 2
			enfiler(file, a->fils[1]);		//On enfile le premier fils
			enfiler(file, a->fils[2]);		//On enfile le deuxième fils
			printf("%i\n", a->cles[1]);		//On affiche l'unique clé
			break;
		case 3:								//Arbre de type 3
			for (int i = 0; i < 3; i++) {  	//On enfile les 3 fils
				enfiler(file, a->fils[i]);
			}
			printf("%i\n", a->cles[0]);		//On affiche les 2 clés
			printf("%i\n", a->cles[1]);
			break;
		case 4:								//Arbre de type 4
			for (int i = 0; i < 4; i++) {	//On enfile les 4 fils
				enfiler(file, a->fils[i]);
			}
			for (int i = 0; i < 3; i++) {	//On affiche les 3 clés
				printf("%i\n", a->cles[i]);
			}
			break;
		default:							//Arbre de type 1 ou autre, cas qui n'est pas supposé arriver
			printf("Error, unknown statement\n");
			break;
		}
	}
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
  if(a->t == 2){//Pour a->t = 2 on a le cas spécial où seulement a->fils[1] et a->fils[2] sont remplis
    //et ce n'est pas a->fils[0] qui est rempli, donc on est obligé de faire un cas à part
    Affichage_Cles_Triees_Recursive(a->fils[1]);
    printf("%i", a->cles[1]);
    Affichage_Cles_Triees_Recursive(a->fils[2]);
    return;
  }
  for(int i = 0; i<a->t; i++){
    Affichage_Cles_Triees_Recursive(a->fils[i]);
    if(i != a->t-1){
      printf("%i", a->cles[i]);
    }
  }
}

void Affichage_Cles_Triees_NonRecursive (Arbre234 a)
{
	int currNoeud;							//Valeur indiquant le noeud fils traité courant du noeud cible
	if (a == NULL) return;					//Sortie anticipée
	if (a->fils[1] == NULL && a->t == 0) {	//Sortie anticipée
		return;
	}
	ppile_t p = creer_pile();				//Création de notre pile avec noeud courant ajouté
	if (a->t == 2) currNoeud = 1;			//Voir les spécifications de a234 et de l'emplacement de ses clés/fils dans le tableau en fonction de son type
	else currNoeud = 0;

	empiler(p, a, currNoeud);				//Empilement de la racine
	while(1) {								//Boucle infinie, on sortira dans le programme quand on aura trouvé une condition d'arrêt
		while (a != NULL && a->t != 0) {	//Etape de plongée, on parcours en profondeur jusqu'à atteindre un noeud fils de feuille (hors arbre)
			if (a->t == 2) currNoeud = 1;	//En fonction du type le noeud courant est différent
			else currNoeud = 0;
			empiler(p, a, currNoeud);		//On empile les noeuds croisés avec leur noeud courant
			if (a->t == 2) a = a->fils[1];						//Passag au fils, toujours en fonction du type
			else if (a->t == 3 || a->t == 4) a = a->fils[0];
		}

		a = depiler(p, &currNoeud);			//On dépile et donc on récupère un noeud feuille
		if (a->t == 2) { if (currNoeud < a->t) printf("%i ", a->cles[currNoeud]); }	//Affichage de la clé, toujours en fonction du type
		else { if (currNoeud < a->t-1) printf("%i ", a->cles[currNoeud]); }

		if (currNoeud < a->t) {				//Cas où l'on n'a pas encore traité tous les fils//Et si la pile est vide la fonction est terminée (à savoir que la racine est empilée deux fois au cours de la fonction et que cette dernière valeur dans la pile est aussi la racine mais comme elle a déjà été traitée la fonction peut se terminer)
			currNoeud++;					//Le noeud courant se décale
			empiler(p, a, currNoeud);		//Et on empile le même noeud mais avec son noeud courant incrémenté
		}
		else {								//Cas où l'on est arrivé en bout de noeud
			do {
				a = depiler(p, &currNoeud);			//On dépile pour remonter au noeud parent
				if (pile_vide(p) == 1) {			//Et si la pile est vide la fonction est terminée (à savoir que la racine est empilée deux fois au cours de la fonction et que cette dernière valeur dans la pile est aussi la racine mais comme elle a déjà été traitée la fonction peut se terminer)
					printf("\n");
					return;
				}
				if (a->t == 2) { if (currNoeud < a->t) printf("%i ", a->cles[currNoeud]); } 	//Affichage, toujour en fonction du type
				else { if (currNoeud < a->t-1) printf("%i ", a->cles[currNoeud]); }
			}
			while (currNoeud >= a->t);		//On continue tant que le parent obtenu et lui aussi arrivé en bout de tableau noeuds
			currNoeud++;					//On incrémente quand même le noeud courant pour le dernier
			empiler(p, a, currNoeud);		//Et on empile
		}
		a = a->fils[currNoeud];				//On passe au fils suivant
	}
}


void Detruire_Cle (Arbre234 *a, int cle)
{
  /*
    retirer la cle de l'arbre a
  */

  return ;
}
