#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	int nb;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	const int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 19};
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i); 
		str = strcat(str, head);
		str = strcat(str, tail); 
		a = lire_arbre (str);
		nb = NombreCles(a);
		printf("Arbre %i, Le nombre de clés est de: %i   ", i, nb);
		printf("Valeur attendue: %i ---> ", expected[i-1]);
		if (nb == expected[i-1]) printf("CORRECT\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
	}
	a = lire_arbre ("data/arbrecours");
	nb = NombreCles(a);
	printf("Arbre cours, Le nombre de clés est de: %i   ", nb);
	printf("Valeur attendue: %i ---> ", 17);
	if (nb == 17) printf("CORRECT\n");
	else printf("ERROR, stop\n");
	free(str);
	free(tail);
}
