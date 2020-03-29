OPTIONS_COMPIL=-Wall -g -c
executables = test_overview_file test_nombreCles test_cleMax test_cleMin test_rechercherCle test_analyseStructureArbre test_noeudMax test_afficherClesLargeur test_affichageClesTrieesRecursive test_affichageClesTrieesNonRecursive test_detruireCle

all: $(executables)

#a234: a234.o lire_affichage.o ajout_cle.o file.o pile.o
	#gcc -o a234 a234.o lire_affichage.o ajout_cle.o file.o pile.o

a234.o: a234.c a234.h file.h pile.h
	gcc $(OPTIONS_COMPIL) a234.c

file.o: file.c file.h
	gcc $(OPTIONS_COMPIL) file.c

pile.o: pile.c pile.h
	gcc $(OPTIONS_COMPIL) pile.c

lire_affichage.o: lire_affichage.c a234.h
	gcc $(OPTIONS_COMPIL) lire_affichage.c

ajout_cle.o : ajout_cle.c a234.h
	gcc $(OPTIONS_COMPIL) ajout_cle.c

detruire_cle.o: detruire_cle.c a234.h detruire_cle.h
	gcc $(OPTIONS_COMPIL) detruire_cle.c

####
test_overview_file: test_overview_file.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_overview_file test_overview_file.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_overview_file.o: test_overview_file.c a234.h
	gcc $(OPTIONS_COMPIL) test_overview_file.c

####
test_nombreCles: test_nombreCles.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_nombreCles test_nombreCles.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_nombreCles.o: test_nombreCles.c a234.h
	gcc $(OPTIONS_COMPIL) test_nombreCles.c

####
test_cleMax: test_cleMax.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_cleMax test_cleMax.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_cleMax.o: test_cleMax.c a234.h
	gcc $(OPTIONS_COMPIL) test_cleMax.c

####
test_cleMin: test_cleMin.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_cleMin test_cleMin.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_cleMin.o: test_cleMin.c a234.h
	gcc $(OPTIONS_COMPIL) test_cleMin.c

####
test_rechercherCle: test_rechercherCle.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_rechercherCle test_rechercherCle.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_rechercherCle.o: test_rechercherCle.c a234.h
	gcc $(OPTIONS_COMPIL) test_rechercherCle.c

####
test_analyseStructureArbre: test_analyseStructureArbre.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_analyseStructureArbre test_analyseStructureArbre.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_analyseStructureArbre.o: test_analyseStructureArbre.c a234.h
	gcc $(OPTIONS_COMPIL) test_analyseStructureArbre.c

####
test_noeudMax: test_noeudMax.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_noeudMax test_noeudMax.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_noeudMax.o: test_noeudMax.c a234.h
	gcc $(OPTIONS_COMPIL) test_noeudMax.c

####
test_afficherClesLargeur: test_afficherClesLargeur.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_afficherClesLargeur test_afficherClesLargeur.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_afficherClesLargeur.o: test_afficherClesLargeur.c a234.h
	gcc $(OPTIONS_COMPIL) test_afficherClesLargeur.c

####
test_affichageClesTrieesRecursive: test_affichageClesTrieesRecursive.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_affichageClesTrieesRecursive test_affichageClesTrieesRecursive.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_affichageClesTrieesRecursive.o: test_affichageClesTrieesRecursive.c a234.h
	gcc $(OPTIONS_COMPIL) test_affichageClesTrieesRecursive.c

####
test_affichageClesTrieesNonRecursive: test_affichageClesTrieesNonRecursive.o a234.o lire_affichage.o ajout_cle.o file.o pile.o
	gcc -o test_affichageClesTrieesNonRecursive test_affichageClesTrieesNonRecursive.o a234.o lire_affichage.o ajout_cle.o file.o pile.o

test_affichageClesTrieesNonRecursive.o: test_affichageClesTrieesNonRecursive.c a234.h
	gcc $(OPTIONS_COMPIL) test_affichageClesTrieesNonRecursive.c

####
test_detruireCle: test_detruireCle.o a234.o lire_affichage.o ajout_cle.o file.o pile.o detruire_cle.o
	gcc -o test_detruireCle test_detruireCle.o a234.o lire_affichage.o ajout_cle.o file.o pile.o detruire_cle.o

test_detruireCle.o: test_detruireCle.c a234.h detruire_cle.h
	gcc $(OPTIONS_COMPIL) test_detruireCle.c

clean:
	rm -rf *.o *~
	rm -rf $(executables)
