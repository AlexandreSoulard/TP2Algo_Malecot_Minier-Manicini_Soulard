#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	int min;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	const int expected[] = {50, 30, 30, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i); 
		str = strcat(str, head);
		str = strcat(str, tail); 
		a = lire_arbre (str);
		min = CleMin(a);
		printf("La clé min est: %i   ", min);
		printf("Valeur attendue: %i ---> ", expected[i-1]);
		if (min == expected[i-1]) printf("CORRECT\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
	}
	a = lire_arbre ("data/arbrecours");
	min = CleMin(a);
	printf("La clé min est: %i   ", min);
	printf("Valeur attendue: %i ---> ", 1);
	if (min == 1) printf("CORRECT\n");
	else printf("ERROR, stop\n");
	free(str);
	free(tail);
}
