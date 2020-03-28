#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	int nbrF = 0;
	int nbrN2 = 0;
	int nbrN3 = 0;
	int nbrN4 = 0;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	const int expectedF[] =  {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5};
	const int expectedN2[] = {1, 0, 0, 2, 2, 1, 1, 1, 1, 0, 1, 4, 3, 3, 3, 2};
	const int expectedN3[] = {0, 1, 0, 1, 0, 1, 0, 2, 1, 2, 1, 0, 1, 0, 2, 1};
	const int expectedN4[] = {0, 0, 1, 0, 1, 1, 2, 1, 2, 2, 3, 3, 3, 4, 3, 5};
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i); 
		str = strcat(str, head);
		str = strcat(str, tail); 
		a = lire_arbre (str);
		AnalyseStructureArbre(a, &nbrF, &nbrN2, &nbrN3, &nbrN4);
		printf("Arbre %i\n", i);
		printf("Nombre de feuilles : %i, Attendu : %i ---> ", nbrF, expectedF[i-1]);
		if (nbrF == expectedF[i-1]) printf("OK\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
		printf("Nombre de Noeud2 : %i, Attendu : %i ---> ", nbrN2, expectedN2[i-1]);
		if (nbrN2 == expectedN2[i-1]) printf("OK\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
		printf("Nombre de Noeud3 : %i, Attendu : %i ---> ", nbrN3, expectedN3[i-1]);
		if (nbrN3 == expectedN3[i-1]) printf("OK\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
		printf("Nombre de Noeud4 : %i, Attendu : %i ---> ", nbrN4, expectedN4[i-1]);	
		if (nbrN4 == expectedN4[i-1]) printf("OK\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
	}
	a = lire_arbre ("data/arbrecours");
	AnalyseStructureArbre(a, &nbrF, &nbrN2, &nbrN3, &nbrN4);
	printf("Arbre Cours \n");
	printf("Nombre de feuilles : %i, Attendu : %i ---> ", nbrF, 6);
	if (nbrF == 6) printf("OK\n");
	else {
		printf("ERROR, stop\n");
		exit(EXIT_FAILURE);
	} 
	printf("Nombre de Noeud2 : %i, Attendu : %i ---> ", nbrN2, 5);
	if (nbrN2 == 5) printf("OK\n");
	else {
		printf("ERROR, stop\n");
		exit(EXIT_FAILURE);
	} 
	printf("Nombre de Noeud3 : %i, Attendu : %i ---> ", nbrN3, 3);
	if (nbrN3 == 3) printf("OK\n");
	else {
		printf("ERROR, stop\n");
		exit(EXIT_FAILURE);
	} 
	printf("Nombre de Noeud4 : %i, Attendu : %i ---> ", nbrN4, 2);	
	if (nbrN4 == 2) printf("OK\n");
	else {
		printf("ERROR, stop\n");
		exit(EXIT_FAILURE);
	} 
	free(str);
	free(tail);
}
