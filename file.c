#include <stdlib.h>

#include "a234.h"
#include "file.h"

pfile_t creer_file ()
{
	pfile_t f = malloc(sizeof(pfile_t));
	if (f == NULL) return NULL;
	f->tete = 0;
	f->queue = 0;
	f->vide = 1;
	return f;
}

int detruire_file (pfile_t f)
{
	free(f);
	return 0;
}

int file_vide (pfile_t f)
{
	if (f->vide) return 1;
	else return 0;
}


int file_pleine (pfile_t f)
{
	if (f->tete == f->queue+1 || (f->tete == 0 && f->queue == MAX_FILE_SIZE-1)) {
		return 1;
	}
	else return 0;
}

pnoeud234 defiler (pfile_t f)
{
	if (file_vide(f)) return NULL;
	else {
		pnoeud234 ret = f->Tab[f->queue];
		if (f->queue == f->tete) f->vide = 1;
		else if (f->queue <= 0) f->queue = MAX_FILE_SIZE-1;
		else f->queue--;
		return ret;
	}
}

int enfiler (pfile_t f, pnoeud234 p)
{
	if (file_pleine(f)) return 0;
	else if (file_vide(f)) {
		f->vide = 0;
		f->Tab[f->tete] = p;
		return 1;
	}
	else {
		if (f->tete <= 0) f->tete = MAX_FILE_SIZE-1;
		else f->tete--;
		f->Tab[f->tete] = p;
		return 1;
	}
}
