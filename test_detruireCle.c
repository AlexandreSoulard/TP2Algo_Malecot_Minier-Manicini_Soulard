#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"
#include "detruire_cle.h"

void testStop(char* c) {
	printf("ERREUR - ARRET DES TESTS, CAUSE : ");
	for(int i = 0; i < strlen(c); i++) {
		printf("%c", c[i]);
	}
	printf("\n");
	exit(EXIT_FAILURE);
}

int main (int argc, char** argv) {
	/*
	Arbre234 a ;

	if (argc != 2)
	{
	  fprintf (stderr, "il manque le parametre nom de fichier\n") ;
	  exit (-1) ;
	}

	a = lire_arbre (argv [1]);
	afficher_arbre(a,0);
	printf("\n------------------------------------\n");
	Arbre234* c = &a;
	int i = -1;
	int* branche = &i;
	Arbre234 b = RechercheCleArbrePere(10, c, branche);
	afficher_arbre(b,0);
	printf("\n------------------------------------\n");
	afficher_arbre(*c,0);
	printf("BRANCHE %i\n", *branche);
	detruire_cle(c,50);
	printf("\n------------------------------------\n");
	afficher_arbre(*c,0);

	*/
	
	Arbre234 misterTest;
	printf("Début des tests...\n");
	printf("Tests sur l'arbre 1...\n");
	misterTest = lire_arbre("data/arbre1");
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	
	printf("--------suppression de la clé 50--------\n");
	detruire_cle(&misterTest, 50);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest == NULL || misterTest->t == 0) {
		printf("L'arbre est vide, c'est la situation attendue ---> SUCCESS\n");
	} else {
		testStop("Arbre non vide apres suppression de son unique clé");
	}
	printf("-------reconstruction de l'arbre 1-------");
	free(misterTest);
	misterTest = lire_arbre("data/arbre1");
	
	printf("--------suppression de la clé 10--------\n");
	detruire_cle(&misterTest, 10);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 50 && misterTest->fils[1] == NULL && misterTest->fils[2] == NULL) {
		printf("L'arbre n'a pas changé, c'est la situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre a été modifié alors que la clé à supprimer n'était pas dedans");
	}
	free(misterTest);
	
	printf("Tests sur l'arbre 2...\n");
	misterTest = lire_arbre("data/arbre2");
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	
	printf("--------suppression de la clé 50--------\n");
	detruire_cle(&misterTest, 50);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 30) {
		printf("Il ne reste plus que la cle 30, c'est la situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	printf("-------reconstruction de l'arbre 2-------");
	free(misterTest);
	misterTest = lire_arbre("data/arbre2");
	
	printf("--------suppression de la clé 30--------\n");
	detruire_cle(&misterTest, 30);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 50) {
		printf("Il ne reste plus que la cle 50, c'est la situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	printf("-------reconstruction de l'arbre 2-------");
	free(misterTest);
	misterTest = lire_arbre("data/arbre2");
	
	printf("--------suppression des clés 30 et 50--------\n");
	detruire_cle(&misterTest, 30);
	detruire_cle(&misterTest, 50);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest == NULL || misterTest->t == 0) {
		printf("L'arbre es vide, c'est la situation attendue ---> SUCCESS\n");
	} else {
		testStop("Arbre non vide après la suppression de ses deux seules clés");
	}
	free(misterTest);
	
	printf("Tests sur l'arbre 5...\n");
	misterTest = lire_arbre("data/arbre5");
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	
	printf("--------suppression de la clé 20--------\n");
	detruire_cle(&misterTest, 20);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 50 && misterTest->fils[1]->t == 3 
		&& misterTest->fils[1]->cles[0] == 10 && misterTest->fils[1]->cles[1] == 30
		&& misterTest->fils[2]->t == 2 && misterTest->fils[2]->cles[1] == 80) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	printf("-------reconstruction de l'arbre 5-------");
	free(misterTest);
	misterTest = lire_arbre("data/arbre5");
	
	printf("--------suppression de la clé 80--------\n");
	detruire_cle(&misterTest, 80);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 30
		&& misterTest->fils[1]->t == 3 && misterTest->fils[1]->cles[0] == 10
		&& misterTest->fils[1]->cles[1] == 20 && misterTest->fils[2]->t == 2
		&& misterTest->fils[2]->cles[1] == 50) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	printf("-------reconstruction de l'arbre 5-------");
	free(misterTest);
	misterTest = lire_arbre("data/arbre5");
	
	printf("--------suppression de la clé 50--------\n");
	detruire_cle(&misterTest, 50);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 30
		&& misterTest->fils[1]->t == 3 && misterTest->fils[1]->cles[0] == 10
		&& misterTest->fils[1]->cles[1] == 20 && misterTest->fils[2]->t == 2
		&& misterTest->fils[2]->cles[1] == 80) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	printf("-------reconstruction de l'arbre 5-------");
	free(misterTest);
	misterTest = lire_arbre("data/arbre5");
	
	printf("--------suppression des clés 30 et 50--------\n");
	detruire_cle(&misterTest, 30);
	detruire_cle(&misterTest, 50);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 4 && misterTest->cles[0] == 10
		&& misterTest->cles[1] == 20 &&  misterTest->cles[2] == 80) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	free(misterTest);
	
	printf("Tests sur l'arbre 16...\n");
	misterTest = lire_arbre("data/arbre16");
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	
	printf("--------suppression de la clé 200--------\n");
	detruire_cle(&misterTest, 200);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 85
		&& misterTest->fils[1]->t == 2 && misterTest->fils[1]->cles[1] == 50
		&& misterTest->fils[1]->fils[2]->t == 3 && misterTest->fils[1]->fils[2]->cles[0] == 80
		&& misterTest->fils[1]->fils[2]->cles[1] == 82 && misterTest->fils[1]->fils[1]->t == 4
		&& misterTest->fils[1]->fils[1]->cles[0] == 10
		&& misterTest->fils[1]->fils[1]->cles[1] == 20 && misterTest->fils[1]->fils[1]->cles[2] == 30
		&& misterTest->fils[2]->t == 3 && misterTest->fils[2]->cles[0] == 280
		&& misterTest->fils[2]->cles[1] == 300) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	
	printf("--------suppression de la clé 50--------\n");
	detruire_cle(&misterTest, 50);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 85
		&& misterTest->fils[1]->t == 2 && misterTest->fils[1]->cles[1] == 30
		&& misterTest->fils[1]->fils[2]->t == 3 && misterTest->fils[1]->fils[2]->cles[0] == 80
		&& misterTest->fils[1]->fils[2]->cles[1] == 82 && misterTest->fils[1]->fils[1]->t == 3
		&& misterTest->fils[1]->fils[1]->cles[0] == 10 && misterTest->fils[1]->fils[1]->cles[1] == 20 
		&& misterTest->fils[2]->t == 3 && misterTest->fils[2]->cles[0] == 280
		&& misterTest->fils[2]->cles[1] == 300) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	
	printf("--------suppression de la clé 30--------\n");
	detruire_cle(&misterTest, 30);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 85
		&& misterTest->fils[1]->t == 2 && misterTest->fils[1]->cles[1] == 20
		&& misterTest->fils[1]->fils[2]->t == 3 && misterTest->fils[1]->fils[2]->cles[0] == 80
		&& misterTest->fils[1]->fils[2]->cles[1] == 82 && misterTest->fils[1]->fils[1]->t == 2
		&& misterTest->fils[1]->fils[1]->cles[1] == 10 
		&& misterTest->fils[2]->t == 3 && misterTest->fils[2]->cles[0] == 280
		&& misterTest->fils[2]->cles[1] == 300) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	
	printf("--------suppression de la clé 20--------\n");
	detruire_cle(&misterTest, 20);
	printf("Affichage :\n");
	afficher_arbre(misterTest, 0);
	if (misterTest->t == 2 && misterTest->cles[1] == 85
		&& misterTest->fils[1]->t == 4 && misterTest->fils[1]->cles[0] == 10
		&& misterTest->fils[1]->cles[1] == 80 && misterTest->fils[1]->cles[2] == 82
		&& misterTest->fils[2]->t == 3 && misterTest->fils[2]->cles[0] == 280
		&& misterTest->fils[2]->cles[1] == 300) {
		printf("Situation attendue ---> SUCCESS\n");
	} else {
		testStop("L'arbre n'a pas été modifié correctement");
	}
	
	printf("Fin des tests basiques prévus");
}
