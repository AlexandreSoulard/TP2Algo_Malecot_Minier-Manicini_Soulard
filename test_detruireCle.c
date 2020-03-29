#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a234.h"
#include "detruire_cle.h"

int main (int argc, char** argv) {
  Arbre234 a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv [1]);
  afficher_arbre(a,0);
  Arbre234* c = &a;
  detruire_cle(c,50);
  afficher_arbre(*c,0);


  /*
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

	}
	free(str);
	free(tail);
	*/
}
