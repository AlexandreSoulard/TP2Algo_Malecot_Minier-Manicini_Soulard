#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	Arbre234 max;
	int maxSum;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	const int expected[] = {50, 80, 160, 80, 80, 280, 530, 550, 900, 900, 720, 1095, 1095, 1095, 1095, 1095};
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i); 
		str = strcat(str, head);
		str = strcat(str, tail); 
		a = lire_arbre (str);
		max = noeud_max(a);
		if (max->t == 2) maxSum = max->cles[1];
		else if (max->t == 3) maxSum = max->cles[0] + max->cles[1];
		else if (max->t == 4) maxSum = max->cles[0] + max->cles[1] + max->cles[2];
		else maxSum = 0;
		printf("La somme des clés du noeud max est: %i   ", maxSum);
		printf("Valeur attendue: %i ---> ", expected[i-1]);
		if (maxSum == expected[i-1]) printf("CORRECT\n");
		else {
			printf("ERROR, stop\n");
			exit(EXIT_FAILURE);
		} 
	}
	a = lire_arbre ("data/arbrecours");
	max = noeud_max(a);
	if (max->t == 2) maxSum = max->cles[1];
	else if (max->t == 3) maxSum = max->cles[0] + max->cles[1];
	else if (max->t == 4) maxSum = max->cles[0] + max->cles[1] + max->cles[2];
	else maxSum = 0;
	printf("La somme des clés du noeud max est: %i   ", maxSum);
	printf("Valeur attendue: %i ---> ", 125);
	if (maxSum == 125) printf("CORRECT\n");
	else printf("ERROR, stop\n");
	free(str);
	free(tail);
}
