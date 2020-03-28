#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	int max;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	const int expected[] = {50, 50, 80, 80, 80, 200, 250, 300, 350, 350, 370, 375, 375, 375, 375, 375};
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i); 
		str = strcat(str, head);
		str = strcat(str, tail); 
		a = lire_arbre (str);
		max = CleMax(a);
		printf("Arbre %i, La clé max est: %i   ", i, max);
		printf("Valeur attendue: %i ---> ", expected[i-1]);
		if (max == expected[i-1]) printf("CORRECT\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
	}
	a = lire_arbre ("data/arbrecours");
	max = CleMax(a);
	printf("Arbre cours, La clé max est: %i   ", max);
	printf("Valeur attendue: %i ---> ", 50);
	if (max == 50) printf("CORRECT\n");
	else printf("ERROR, stop\n");
	free(str);
	free(tail);
}
