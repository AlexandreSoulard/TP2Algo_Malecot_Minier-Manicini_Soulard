#include <stdlib.h>
#include "a234.h"
#include "pile.h"

ppile_t creer_pile ()
{
  ppile_t p = malloc(sizeof(pile_t));
  if  (p == NULL) return NULL;
  p->sommet = -1;
  return p;
}

int detruire_pile (ppile_t p)
{
  free(p);
  return 0;
}

int pile_vide (ppile_t p)
{
  if (p->sommet==-1) {
    return 1;
  } else {
    return 0 ;
  }
}

int pile_pleine (ppile_t p)
 {
   if (p->sommet == MAX_PILE_SIZE-1) {
     return 1;
   } else {
     return 0;
   }
}

pnoeud234 depiler (ppile_t p, int* currNoeud)
{
  if (pile_vide(p)==0) {
    pnoeud234 res = p->Tab[p->sommet];
    *currNoeud = p->currNoeud[p->sommet];
    p->sommet --;
    return res;
  } else {
    return NULL;
  }
}

int empiler (ppile_t p, pnoeud234 pn, int currNoeud)
  {
    if (pile_pleine(p)==0){
      p->sommet ++;
      p->currNoeud[p->sommet] = currNoeud;
      p->Tab[p->sommet]= pn;
      return 1;
    } else {
      return 0;
    }
}
