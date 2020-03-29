#include <stdio.h>
#include <stdlib.h>

#include "a234.h"
#include "detruire_cle.h"

Arbre234 RechercheCleArbrePere (int cle, Arbre234 *padre, int *branche) {       //branche permet de garder en mémoire l'indice auquel se trouve le fils par rapport au père
  Arbre234 pere = *padre;
  if (pere == NULL || pere->t==0){
    return NULL;
  }

//### On parocourt l'arbre pere ###
//Cas où le parent est un noeud2
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

//Si la clé n'est pas trouvé dans l'un des fils du noeud courant, on recommence sur les fils

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


//Cas où le parent est un noeud3
  } else if (pere->t==3){

//### On différencie les cas en fonction du type des fils considérés (noeud2-noeud3-noeud4) ###

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

//### si la clé n'est pas trouvé dans un fils, on recommence dans ses fils ###

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

//### Cas du noeud4

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

Arbre234 Fusion (Arbre234 arbre){
 if (arbre==NULL || arbre->t==0){
   printf("Fusion impossible car arbre vide\n");
   return NULL;
 } else if (arbre->t==2){

//### Fusion dans le cas où le noeud considéré est un noeud2 avec deux fils noeud2 pour former un noeud4

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
   } else {
     printf("Cette fusion n'a pas encore était implémentée\n");
     return NULL;
   }
/*
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
}
void detruire_cle_aux(Arbre234 *a, Arbre234* arbre_principal, int cle){
  Arbre234 arbre = *a;
  

//### Cas où l'on se place dand un Noeud2 ###

  if (arbre->t==2){
    if (arbre->cles[1]==cle){
      int indice =-1;
      int* pindice = &indice;
      RechercheCleArbrePere(cle, arbre_principal, pindice);   //Il faut regarder le parent pour savoir comment modifier l'arbre
      Arbre234 pere = *arbre_principal;
      //afficher_arbre(pere,0);                       //verification du fonctionnement de RechercheCleArbrePere
      /*
      if(pere->fils[*pindice]!=NULL){
        afficher_arbre(pere->fils[*pindice],0);
      }
      */

//### Cas dependant du nombre de fils du parent ###

      if (pere==NULL && *pindice==-1 && (arbre->fils[0]==NULL || arbre->fils[0]->t==0) && (arbre->fils[1]==NULL || arbre->fils[1]->t==0)){
        arbre = NULL;
        return;                                 //l'arbre ne contient qu'un seul noeud celui à supprimer
      } else if (pere==NULL && *pindice==-1){
        printf("Error : Pas de parent au noeud que vous souhaitez supprimer\n");
        return;

//### Cas où le père possède 2 fils ###

      } else if (pere->t==2){
        if (pere->fils[1]->t==2 && pere->fils[2]->t==2){  //pere est un noeud2 et c'est 2 fils aussi donc il aurait du etre fusionné en noeud4
          printf("Error :Le noeud2 pere et ces fils auraient du être fusionné lors de la destruciton précédente\n");
          Fusion(pere);
          printf("Correction de l'erreur :OK\n");

          return;

//### Cas où le noeud qui possède la clé à supprimer est le 2eme fils du parent (on différencie les cas en fonction du nombre de clé dans l'autre fils)

        } else if(*pindice==2){
          if (pere->fils[1]==NULL || pere->fils[1]->t==0){
            printf("Error : Voisin NULL\n");
            return;
          } else if (pere->fils[1]->t==3){           //On fait passer la clé voisine la plus à droite en cle du père et le père viens formé un noeud3 avec le noeud qui contient la clé que l'on veut supprimer
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = pere->cles[1];
            pere->cles[1] = pere->fils[1]->cles[1];
            pere->fils[1]->t=2;
            pere->fils[1]->cles[1]=pere->fils[1]->cles[0];
            arbre->fils[0]=pere->fils[1]->fils[2];
            afficher_arbre(pere,0);
            detruire_cle(arbre_principal, cle);  //On peut maintenant détruire la clé qui n'est plus seule sur 1 noeud ou la refaire descendre dans l'arbre si besoin
          } else if (pere->fils[1]->t==4){          //Cas d'un voisin noeud4
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0]= pere->cles[1];
            pere->cles[1] = pere->fils[1]->cles[2];
            pere->fils[1]->t=3;
            arbre->fils[0]=pere->fils[1]->fils[3];
            afficher_arbre(pere, 0);
            detruire_cle(arbre_principal, cle);
          }

//### Cas où le noeud qui possède la clé à supprimer est le 1er fils du parent

        } else if (*pindice ==1){
          if (pere->fils[2]==NULL || pere->fils[2]->t==0){
            printf("Error : Voisin NULL\n");
            return;
          } else if (pere->fils[2]->t==3){           //On fait passer la clé voisine la plus à droite en cle du père et le père viens formé un noeud3 avec le noeud qui contient la clé que l'on veut supprimer
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = arbre->cles[1];
            arbre->cles[1] = pere->cles[1];
            pere->cles[1] = pere->fils[2]->cles[0];
            pere->fils[2]->t=2;
            arbre->fils[2]=pere->fils[2]->fils[0];
            afficher_arbre(pere,0);
            detruire_cle(arbre_principal, cle);  //On peut maintenant détruire la clé qui n'est plus seule sur 1 noeud ou la refaire descendre dans l'arbre si besoin
          } else if (pere->fils[1]->t==4){
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = arbre->cles[1];
            arbre->cles[1] = pere->cles[1];
            pere->cles[1] = pere->fils[2]->cles[0];
            pere->fils[2]->cles[0] = pere->fils[2]->cles[1];
            pere->fils[2]->cles[1] = pere->fils[2]->cles[2];
            pere->fils[2]->t=3;
            arbre->fils[2]=pere->fils[2]->fils[0];
            afficher_arbre(pere, 0);
            detruire_cle(arbre_principal, cle);
          }
        }
<<<<<<< HEAD

//### Cas où le père possède 3 fils

      } else if(pere->t==3){
        if (*pindice==3){
          printf("Indice du fils invalide\n");
=======
        if (pere->t==2 && pere->fils[1]->t == 2 && pere->fils[2]->t == 2){
          printf("Le noeud2 pere et ces fils auraient du être fusionné lors de la destruciton précédente\n");
>>>>>>> f7eb1d269967f48694c25dd0ca496394f95b8f9f
          return;

//### Cas où la clé cherché se trouve dans le fils numéro 2

        } else if (*pindice==2){
          if (pere->fils[1]==NULL || pere->fils[1]->t==0){
            printf("Error : Voisin NULL\n");
            return;
          } else if (pere->fils[1]->t==3){           //On fait passer la clé voisine la plus à droite en cle du père et le père viens formé un noeud3 avec le noeud qui contient la clé que l'on veut supprimer
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = pere->cles[2];
            pere->cles[2] = pere->cles[1];
            pere->cles[1] = pere->fils[1]->cles[1];
            pere->fils[1]->cles[1] = pere->fils[1]->cles[0];
            pere->fils[1]->t=2;
            arbre->fils[0]=pere->fils[1]->fils[2];
            afficher_arbre(pere,0);
            detruire_cle(arbre_principal, cle);  //On peut maintenant détruire la clé qui n'est plus seule sur 1 noeud ou la refaire descendre dans l'arbre si besoin
          } else if (pere->fils[1]->t==4){
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0]= pere->cles[2];
            pere->cles[2] = pere->cles[1];
            pere->cles[1] = pere->fils[1]->cles[2];
            pere->fils[1]->t=3;
            arbre->fils[0]=pere->fils[1]->fils[3];
            afficher_arbre(pere, 0);
            detruire_cle(arbre_principal, cle);
          }

//### Cas où la clé recherchée se trouve dans le fils du milieu le numéro 1

        } else if (*pindice ==1){                               //Dans le cas ou le fils à traité est le fils du milieu, il peut y avoir une rotation par la gauche ou par la droite
          if (pere->fils[2]==NULL || pere->fils[2]->t==0){
            printf("Error : Voisin droit NULL\n");
            return;
          } else if (pere->fils[0]==NULL || pere->fils[0]->t==0){
            printf("Error : Voisin gauche NULL");
            return;
          } else if (pere->fils[0]->t==3){
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = pere->cles[1];
            pere->cles[1] = pere->cles[0];
            pere->cles[0] = pere->fils[0]->cles[1];
            pere->fils[0]->cles[1] = pere->fils[0]->cles[0];
            pere->fils[0]->t=2;
            arbre->fils[0]=pere->fils[0]->fils[2];
            afficher_arbre(pere,0);
            detruire_cle(arbre_principal, cle);
          } else if (pere->fils[0]->t==4){
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0]= pere->cles[1];
            pere->cles[1] = pere->cles[0];
            pere->cles[0] = pere->fils[0]->cles[2];
            pere->fils[0]->t=3;
            arbre->fils[0]=pere->fils[0]->fils[3];
            afficher_arbre(pere, 0);
            detruire_cle(arbre_principal, cle);
          } else if (pere->fils[2]->t==3){           //On fait passer la clé voisine la plus à droite en cle du père et le père viens formé un noeud3 avec le noeud qui contient la clé que l'on veut supprimer
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = arbre->cles[1];
            arbre->cles[1] = pere->cles[1];
            pere->cles[1] = pere->fils[2]->cles[0];
            pere->fils[2]->t=2;
            arbre->fils[2]=pere->fils[2]->fils[0];
            afficher_arbre(pere,0);
            detruire_cle(arbre_principal, cle);
          } else if (pere->fils[2]->t==4){
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = arbre->cles[1];
            arbre->cles[1] = pere->cles[1];
            pere->cles[1] = pere->fils[2]->cles[0];
            pere->fils[2]->cles[0] = pere->fils[2]->cles[1];
            pere->fils[2]->cles[1] = pere->fils[2]->cles[2];
            pere->fils[2]->t=3;
            arbre->fils[2]=pere->fils[2]->fils[0];
            afficher_arbre(pere, 0);
            detruire_cle(arbre_principal, cle);
          }

//### Cas où la clé recherchée se trouve dans le fils numéro 0

        } else if(*pindice == 0){
          if (pere->fils[1]==NULL || pere->fils[1]->t==0){
            printf("Error : Voisin NULL\n");
            return;
          } else if (pere->fils[1]->t==3){           //On fait passer la clé voisine la plus à droite en cle du père et le père viens formé un noeud3 avec le noeud qui contient la clé que l'on veut supprimer
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = arbre->cles[1];
            arbre->cles[1] = pere->cles[0];
            pere->cles[0] = pere->cles[1];
            pere->cles[1] = pere->fils[1]->cles[0];
            pere->fils[1]->t=2;
            arbre->fils[2]=pere->fils[1]->fils[0];
            afficher_arbre(pere,0);
            detruire_cle(arbre_principal, cle);  //On peut maintenant détruire la clé qui n'est plus seule sur 1 noeud ou la refaire descendre dans l'arbre si besoin
          } else if (pere->fils[1]->t==4){
            afficher_arbre(pere,0);
            arbre->t=3;
            arbre->cles[0] = arbre->cles[1];
            arbre->cles[1] = pere->cles[0];
            pere->cles[0] = pere->cles[1];
            pere->cles[1] = pere->fils[1]->cles[0];
            pere->fils[1]->cles[0] = pere->fils[1]->cles[1];
            pere->fils[1]->cles[1] = pere->fils[1]->cles[2];
            pere->fils[1]->t=3;
            arbre->fils[2]=pere->fils[1]->fils[0];
            afficher_arbre(pere, 0);
            detruire_cle(arbre_principal, cle);
          }
        }
      }

    }
    Arbre234 b = arbre->fils[1];
    Arbre234 c = arbre->fils[2];
    detruire_cle_aux(&b, arbre_principal, cle);
    detruire_cle_aux(&c, arbre_principal, cle);

//### Cas où le noeud possèdant la clé recherchée est un noeud 3 ###

  }else if (arbre->t==3){

//### Cas où la clé se trouve sur une feuille d'un noeud3 ###

    if (arbre->cles[0]==cle && (arbre->fils[0]==NULL || arbre->fils[0]->t==0) && (arbre->fils[1]==NULL || arbre->fils[1]->t==0)){
      arbre->t = 2;
      arbre->cles[0]= 0;
    } else if (arbre->cles[1]==cle && (arbre->fils[1]==NULL || arbre->fils[1]->t==0) && (arbre->fils[2]==NULL || arbre->fils[2]->t==0)){
      arbre->t = 2;
      arbre->cles[1]=arbre->cles[0];
      arbre->cles[0]=0;
    }

//### On recommence sur les sous-arbres si la clé n'est pas trouvée ###

    Arbre234 b = arbre->fils[0];
    Arbre234 c = arbre->fils[1];
    Arbre234 d = arbre->fils[2];
    detruire_cle_aux(&b,arbre_principal ,cle);
    detruire_cle_aux(&c,arbre_principal ,cle);
    detruire_cle_aux(&d,arbre_principal ,cle);

//### Cas du noeud4 ###

  } else if (arbre->t==4){

//### Cas des feuilles du noeud4 ###

    if (arbre->cles[0]==cle && (arbre->fils[0]==NULL || arbre->fils[0]->t==0) && (arbre->fils[1]==NULL || arbre->fils[1]->t==0)){
      arbre->t=3;
      arbre->cles[0]= arbre->cles[1];
      arbre->cles[1]= arbre->cles[2];
      arbre->cles[2]= 0;
    } else if (arbre->cles[1]==cle && (arbre->fils[1]==NULL || arbre->fils[1]->t==0) && (arbre->fils[2]==NULL || arbre->fils[2]->t==0)){
      arbre->t=3;
      arbre->cles[1]=arbre->cles[2];
      arbre->cles[2]=0;
    } else if (arbre->cles[2]==cle && (arbre->fils[2]==NULL || arbre->fils[2]->t==0) && (arbre->fils[3]==NULL || arbre->fils[3]->t==0)){
      arbre->t=3;
      arbre->cles[2]=0;
    }

//### On recommence sur les sous-arbres si la clé n'est pas trouvée ###

    Arbre234 b = arbre->fils[0];
    Arbre234 c = arbre->fils[1];
    Arbre234 d = arbre->fils[2];
    Arbre234 e = arbre->fils[3];
    detruire_cle_aux(&b,arbre_principal,cle);
    detruire_cle_aux(&c,arbre_principal,cle);
    detruire_cle_aux(&d,arbre_principal,cle);
    detruire_cle_aux(&e, arbre_principal,cle);
  }
}


void detruire_cle (Arbre234 *a, int cle){               //La fonction detruire_cle n'est pas directement récursive car il faut garder l'arbre général pour appeler la fonction RechercheCleArbrePere donc on passe par une fonction auxilliaire
  Arbre234 arbre = *a;
  if (arbre==NULL || arbre->t==0){                      //vérification du cas d'arrêt
    printf("Arbre vide pas de destruction possible\n");
    return;
  } else {
    Arbre234 *arbre_principal = malloc(sizeof(Arbre234));
    *arbre_principal = arbre;
    detruire_cle_aux(arbre_principal, a, cle);
  }
}
