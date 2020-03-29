#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"

int main (int argc, char** argv) {
	Arbre234 a;
	char* head = "data/arbre";
	char* tail = malloc(2);
	char* str = malloc(1);
	const int list[] = {10, 20, 30, 50, 80, 82, 85, 200, 250, 252, 254, 280, 285, 290, 296, 300, 350, 370, 375, 37, 29};
	const int expected[16][21] = {
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};
	for (int i = 1; i < 17; i++) {
		free(str);
		str = malloc(1);
		sprintf(tail, "%d", i);
		str = strcat(str, head);
		str = strcat(str, tail);
		a = lire_arbre (str);
		for (int j = 0; j < 21; j++) {
			Arbre234 b = RechercherCle(a, list[j]);
			printf("Arbre %i, clé %i : ", i, list[j]);
			if (b == NULL) {
				if (expected[i-1][j] == 0) printf("Non trouvé, résultat attendu: non trouvé ---> OK\n");
				else {
					printf("Non trouvé, résultat attendu: trouvé ---> ERROR, stop\n");
					exit(EXIT_FAILURE);
				}
			}
			else {
				if (expected[i-1][j] == 0) {
					printf("Trouvé, résultat attendu: non trouvé ---> ERROR, stop\n");
					exit(EXIT_FAILURE);
				}
				else printf("Trouvé, résultat attendu: trouvé ---> OK\n");
			}
		}
	}
	free(str);
	free(tail);
}
