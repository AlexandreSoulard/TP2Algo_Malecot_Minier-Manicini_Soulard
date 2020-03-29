#include <stdio.h>
#include <stdlib.h>

#include "a234.h"

Arbre234 RechercheCleArbrePere (int cle, Arbre234 *padre, int *branche) {
  Arbre234 pere = *padre;
  if (pere == NULL || pere->t==0){
    return NULL;
  }
  if (pere->t==2){
    if (pere->fils[1]!=NULL){
      if (pere->fils[1]->t==2){
        if (pere->fils[1]->cles[1]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[1]->t==3){
        if (pere->fils[1]->cles[0]==cle || pere->fils[1]->cles[1]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      } else {
        if (pere->fils[1]->cles[0]==cle || pere->fils[1]->cles[1]==cle || pere->fils[1]->cles[2]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      }
    }
      if (pere->fils[2]!=NULL){
        if (pere->fils[2]->t==2){
          if (pere->fils[2]->cles[1]==cle){
            *branche = 2;
            padre = &pere;
            return pere;
          }
        } else if(pere->fils[2]->t==3){
          if (pere->fils[2]->cles[0]==cle || pere->fils[2]->cles[1]==cle){
            *branche = 2;
            padre = &pere;
            return pere;
          }
        } else {
          if (pere->fils[2]->cles[0]==cle || pere->fils[2]->cles[1]==cle || pere->fils[2]->cles[2]==cle){
            *branche = 2;
            padre = &pere;
            return pere;
          }
      }
  }
  Arbre234 res=NULL;
  Arbre234 res2=NULL;
  if (pere->fils[1]!=NULL){
    Arbre234 a = pere->fils[1];
    res = RechercheCleArbrePere(cle, &a, branche);
  }
  if (pere->fils[2]!=NULL){
    Arbre234 b = pere->fils[2];
    res2 = RechercheCleArbrePere(cle, &b, branche);
  }
  if (res2!=NULL){
    return res2;
  } else {
    return res;
  }

  } else if (pere->t==3){
    if (pere->fils[1]!=NULL){
      if (pere->fils[1]->t==2){
        if (pere->fils[1]->cles[1]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[1]->t==3){
        if (pere->fils[1]->cles[0]==cle || pere->fils[1]->cles[1]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[1]->t==4){
        if (pere->fils[1]->cles[0]==cle || pere->fils[1]->cles[1]==cle || pere->fils[1]->cles[2]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      }
    }
    if (pere->fils[2]!=NULL){
      if (pere->fils[2]->t==2){
        if (pere->fils[2]->cles[1]==cle){
          *branche = 2;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[2]->t==3){
        if (pere->fils[2]->cles[0]==cle || pere->fils[2]->cles[1]==cle){
          *branche = 2;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[2]->t==4) {
        if (pere->fils[2]->cles[0]==cle || pere->fils[2]->cles[1]==cle || pere->fils[2]->cles[2]==cle){
          *branche = 2;
          padre = &pere;
          return pere;
        }
      }
    }
    if (pere->fils[0]!=NULL){
      if (pere->fils[0]->t==2){
        if (pere->fils[0]->cles[1]==cle){
          *branche = 0;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[0]->t==3){
        if (pere->fils[0]->cles[0]==cle || pere->fils[0]->cles[1]==cle){
          *branche = 0;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[0]->t==4){
        if (pere->fils[0]->cles[0]==cle || pere->fils[0]->cles[1]==cle || pere->fils[0]->cles[2]==cle){
          *branche = 0;
          padre = &pere;
          return pere;
        }
      }
    }
    Arbre234 res = NULL;
    Arbre234 res2 = NULL;
    Arbre234 res3 = NULL;
    if (pere->fils[1]!=NULL){
      Arbre234 a = pere->fils[1];
      res = RechercheCleArbrePere(cle, &a, branche);
    }
    if (pere->fils[2]!=NULL){
      Arbre234 b = pere->fils[2];
      res2 = RechercheCleArbrePere(cle, &b,branche);
    }
    if (pere->fils[0]!=NULL){
      Arbre234 c = pere->fils[0];
      res3 = RechercheCleArbrePere(cle, &c, branche);
    }
    if (res2!=NULL){
      return res2;
    } else if (res3!=NULL){
      return res3;
    } else {
      return res;
    }
  } else {
    if (pere->fils[1]!=NULL){
      if (pere->fils[1]->t==2){
        if (pere->fils[1]->cles[1]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[1]->t==3){
        if (pere->fils[1]->cles[0]==cle || pere->fils[1]->cles[1]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[1]->t==4){
        if (pere->fils[1]->cles[0]==cle || pere->fils[1]->cles[1]==cle || pere->fils[1]->cles[2]==cle){
          *branche = 1;
          padre = &pere;
          return pere;
        }
      }
    }
    if (pere->fils[2]!=NULL){
      if (pere->fils[2]->t==2){
        if (pere->fils[2]->cles[1]==cle){
          *branche = 2;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[2]->t==3){
        if (pere->fils[2]->cles[0]==cle || pere->fils[2]->cles[1]==cle){
          *branche = 2;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[2]->t==4) {
        if (pere->fils[2]->cles[0]==cle || pere->fils[2]->cles[1]==cle || pere->fils[2]->cles[2]==cle){
          *branche = 2;
          padre = &pere;
          return pere;
        }
      }
    }
    if (pere->fils[0]!=NULL){
      if (pere->fils[0]->t==2){
        if (pere->fils[0]->cles[1]==cle){
          *branche = 0;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[0]->t==3){
        if (pere->fils[0]->cles[0]==cle || pere->fils[0]->cles[1]==cle){
          *branche = 0;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[0]->t==4){
        if (pere->fils[0]->cles[0]==cle || pere->fils[0]->cles[1]==cle || pere->fils[0]->cles[2]==cle){
          *branche = 0;
          padre = &pere;
          return pere;
        }
      }
    }
    if (pere->fils[3]!=NULL){
      if (pere->fils[3]->t==2){
        if (pere->fils[3]->cles[1]==cle){
          *branche = 3;
          padre = &pere;
          return pere;
        }
      } else if(pere->fils[3]->t==3){
        if (pere->fils[3]->cles[0]==cle || pere->fils[3]->cles[1]==cle){
          *branche = 3;
          padre = &pere;
          return pere;
        }
      } else if (pere->fils[3]->t==4){
        if (pere->fils[3]->cles[0]==cle || pere->fils[3]->cles[1]==cle || pere->fils[3]->cles[2]==cle){
          *branche = 3;
          padre = &pere;
          return pere;
        }
      }
    }
    Arbre234 res = NULL;
    Arbre234 res2 = NULL;
    Arbre234 res3 = NULL;
    Arbre234 res4 = NULL;
    if (pere->fils[1]!=NULL){
      Arbre234 a = pere->fils[1];
      res = RechercheCleArbrePere(cle, &a, branche);
    }
    if (pere->fils[2]!=NULL){
      Arbre234 b = pere->fils[2];
      res2 = RechercheCleArbrePere(cle, &b, branche);
    }
    if (pere->fils[0]!=NULL){
      Arbre234 c = pere->fils[0];
      res3 = RechercheCleArbrePere(cle, &c, branche);
    }
    if (pere->fils[3]!=NULL){
      Arbre234 d = pere->fils[3];
      res4 = RechercheCleArbrePere(cle, &d, branche);
    }

    if (res2!=NULL){
      return res2;
    } else if (res3!=NULL){
      return res3;
    } else if(res4!=NULL){
      return res4;
    } else {
      return res;
    }
  }
}

Arbre234 Fusion (Arbre234 arbre, int indice){
 /*if (arbre==NULL || arbre->t==0){
   printf("Fusion impossible car arbre vide\n");
   return NULL;
 } else if (arbre->t==2){
   if (arbre->fils[1]!=NULL && arbre->fils[2]!=NULL && arbre->fils[1]->t==2 && arbre->fils[2]->t==2){
     arbre->t = 4;
     arbre->cles[0]=arbre->fils[1]->cles[1];
     arbre->cles[2]=arbre->fils[2]->cles[1];
     arbre->fils[0]=arbre->fils[1]->fils[1];
     arbre->fils[1]=arbre->fils[1]->fils[2];
     arbre->fils[2]=arbre->fils[2]->fils[1];
     arbre->fils[3]=arbre->fils[2]->fils[2];
     return arbre;
   } else {
     printf("Pas de fusion possible dans ce cas\n");
     return NULL;
   }
 } else if(arbre->t==3){
   if(arbre->fils[1]!=NULL && arbre->fils[2]!=NULL && arbre->fils[0]!=NULL){
     if (t==1){
       if (arbre->fils[0]->t==2 && arbre->fils[1]->t==2){
         arbre->t=2;
         arbre->fils[1]->t=3;
         arbre->fils[1]->cles[0]=arbre->fils[0]->cles[1];
       }
     }
   }
 }
 */
 return NULL;
}

void detruire_cle (Arbre234 *a, int cle){
  Arbre234 arbre = *a;
  if (arbre==NULL || arbre->t==0){                      //vérification du cas d'arrêt
    //printf("Arbre vide pas de destruction possible\n");
    return;
  } else {
    if (arbre->t==2){                                   //cas d'un noeud2
      if (arbre->cles[1]==cle){
        int indice =-1;
        int* pindice = &indice;
        RechercheCleArbrePere(cle, a, pindice);
        Arbre234 pere = *a;
        if (pere==NULL && *pindice==-1 && (arbre->fils[0]==NULL || arbre->fils[0]->t==0) && (arbre->fils[1]==NULL || arbre->fils[1]->t==0)){
          arbre = NULL;
        } else if (pere==NULL && *pindice==-1){
          printf("Error : Pas de parent au noeud que vous souhaitez supprimer\n");
          return;
        }
        if (pere->t==2 && pere->fils[1]->t == 2 && pere->fils[2]->t == 2){
          printf("Le noeud2 pere et ces fils auraient du être fusionné lors de la destruciton précédente\n");
          return;
        } else if(pere->t==3){
          if (*pindice==3){
            printf("Indice du fils invalide\n");
            return;
          } else if (*pindice==2){
            if (pere->fils[1]!=NULL && pere->fils[1]->t!=0){
              if (pere->fils[1]->t==2){

              }
            }
          }
        }

      }
      Arbre234 b = arbre->fils[1];
      Arbre234 c = arbre->fils[2];
      detruire_cle(&b,cle);
      detruire_cle(&c,cle);
    }else if (arbre->t==3){
      if (arbre->cles[0]==cle && (arbre->fils[0]==NULL || arbre->fils[0]->t==0) && (arbre->fils[1]==NULL || arbre->fils[1]->t==0)){
        arbre->t = 2;
        arbre->cles[0]= 0;
      } else if (arbre->cles[1]==cle && (arbre->fils[1]==NULL || arbre->fils[1]->t==0) && (arbre->fils[2]==NULL || arbre->fils[2]->t==0)){
        arbre->t = 2;
        arbre->cles[1]=arbre->cles[0];
        arbre->cles[0]=0;
      }
      Arbre234 b = arbre->fils[0];
      Arbre234 c = arbre->fils[1];
      Arbre234 d = arbre->fils[2];
      detruire_cle(&b,cle);
      detruire_cle(&c,cle);
      detruire_cle(&d,cle);
    } else if (arbre->t==4){
      if (arbre->cles[0]==cle && (arbre->fils[0]==NULL || arbre->fils[0]->t==0) && (arbre->fils[1]==NULL || arbre->fils[1]->t==0)){
        arbre->t=3;
        arbre->cles[0]= arbre->cles[1];
        arbre->cles[1]= arbre->cles[2];
        arbre->cles[2]= 0;
        afficher_arbre(arbre,0);
      } else if (arbre->cles[1]==cle && (arbre->fils[1]==NULL || arbre->fils[1]->t==0) && (arbre->fils[2]==NULL || arbre->fils[2]->t==0)){
        arbre->t=3;
        arbre->cles[1]=arbre->cles[2];
        arbre->cles[2]=0;
      } else if (arbre->cles[2]==cle && (arbre->fils[2]==NULL || arbre->fils[2]->t==0) && (arbre->fils[3]==NULL || arbre->fils[3]->t==0)){
        arbre->t=3;
        arbre->cles[2]=0;
      }
      Arbre234 b = arbre->fils[0];
      Arbre234 c = arbre->fils[1];
      Arbre234 d = arbre->fils[2];
      Arbre234 e = arbre->fils[3];
      detruire_cle(&b,cle);
      detruire_cle(&c,cle);
      detruire_cle(&d,cle);
      detruire_cle(&e,cle);
    }
  }
}
