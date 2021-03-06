#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i); 
		str = strcat(str, head);
		str = strcat(str, tail); 
		a = lire_arbre (str);
		printf("--------------------------------------------\n");
		printf("AFFICHAGE ARBRE %i :\n", i);
		afficher_arbre(a, 0);
		printf("AFFICHAGE CLES TRIEES ARBRE %i :\n", i);
		 Affichage_Cles_Triees_NonRecursive(a);
	}
	a = lire_arbre ("data/arbrecours");
	printf("--------------------------------------------\n");
	printf("AFFICHAGE ARBRE COURS :\n");
	afficher_arbre(a, 0);
	printf("AFFICHAGE CLES TRIEES ARBRE COURS :\n");
	Affichage_Cles_Triees_NonRecursive(a);
	free(str);
	free(tail);
}
