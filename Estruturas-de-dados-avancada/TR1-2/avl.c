#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int chave;
	int bal;
	struct no *esq;
	struct no *dir;
}NO;
int rotate_left(NO **pt);
int rotate_right(NO **pt);
int rotate_right_remove(NO **pt);
int rotate_left_remove (NO **pt);
int insert_AVL(NO **pt,int chave);
int seach_NO(NO *pt,int chave);
void print_preorder(NO *pt);
int height_tree(NO *pt,int height);
int test_avl(NO *pt);
int count_NO(NO *pt);
void destroy_tree(NO *pt);
int balance_remove(NO **pt,int side);
int logica_remove(NO **pt,int chave);
int remove_AVL(NO **pt,int chave);

int main(){
  NO *raiz = NULL;
  srand(time(NULL));
  for(int j = 0;j<100;j++){//quant avls
    int i = 0;
    raiz = NULL;
    while (i<1000){//quant nos por avl
      if((insert_AVL(&raiz,(1+rand()%10000)))){
        i++;
      }
    }
    printf("\ninfo tree %i: quant. nos? %i ,é AVL? %i ",j,count_NO(raiz),test_avl(raiz));
    for(i = 0;i<100;i++){//quant remocao
      remove_AVL(&raiz,raiz->chave);
    }
    printf("\nremovendo 100nos... quant. nos? %i ,é AVL? %i \n",count_NO(raiz),test_avl(raiz));
    destroy_tree(raiz);
  }
  return 0;
}
int rotate_left(NO **pt){ //rotate left
  NO *ptu = (*pt)->dir;
  if(ptu->bal == 1){
    (*pt)->dir = ptu->esq; ptu->esq = (*pt);
    (*pt)->bal = 0; (*pt)= ptu;
  }else{
    NO *ptv;
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu; 
    (*pt)->dir = ptv->esq;
    ptv->esq= (*pt);
    if(ptv->bal == 1){
      (*pt)->bal = -1;
    }else{
      (*pt)->bal = 0;
    }
    if(ptv->bal == -1){
      ptu->bal = 1;
    }else{
      ptu->bal = 0;
    }
    (*pt) = ptv; 
    }
  (*pt)->bal = 0;
  return 0;
}
int rotate_right(NO **pt){ //rotate right
  NO *ptu = (*pt)->esq;
  if(ptu->bal == -1){
    (*pt)->esq = ptu->dir;
    ptu->dir = (*pt);
    (*pt)->bal = 0;
    (*pt) = ptu;
  }else{
    NO *ptv;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    (*pt)->esq = ptv->dir;
    ptv->dir = (*pt);
    if(ptv->bal == -1){
      (*pt)->bal = 1;
    }else{
      (*pt)->bal = 0;
    }
    if(ptv->bal == 1){
      ptu->bal = -1;
    }else{
      ptu->bal = 0;
    }
    (*pt) = ptv;
    }
  (*pt)->bal = 0;
  return 0;
}
int rotate_right_remove(NO **pt){
    NO *ptu = (*pt)->esq;
    if (ptu->bal <= 0){ //simples
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        (*pt) = ptu;
        if (ptu->bal == -1){
            ptu->bal = (*pt)->dir->bal = 0;
            return 1;
        }else{
            ptu->bal = 1;
            (*pt)->dir->bal = -1;
            return 0;
        }
    }else{ //dupla
        NO *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        (*pt)->esq = ptv->dir;
        ptv->esq = ptu;
        ptv->dir = (*pt);
        (*pt) = ptv;
        switch (ptv->bal){
        case -1:ptu->bal = 0; (*pt)->dir->bal = 1;break;
        case 0: ptu->bal = 0; (*pt)->dir->bal = 0; break;
        case 1: ptu->bal = -1;(*pt)->dir->bal = 0; break;
        }
        (*pt)->bal = 0;
        return 1;
    }
}
int rotate_left_remove (NO **pt){
    NO *ptz = (*pt)->dir;
    if (ptz->bal >= 0){ //simples
        (*pt)->dir = ptz->esq;
        ptz->esq = (*pt);
        (*pt) = ptz;
        if (ptz->bal == 1){
            ptz->bal = (*pt)->esq->bal = 0;
            return 1;
        }else{
            ptz->bal = -1;
            (*pt)->esq->bal = 1;
            return 0;
        }
    }else{ //dupla
        NO *pty = ptz->esq;
        ptz->esq = pty->dir;
        (*pt)->dir = pty->esq;
        pty->dir = ptz;
        pty->esq = (*pt);
        (*pt) = pty;
        switch (pty->bal){
        case -1: ptz->bal = 1;  (*pt)->esq->bal = 0; break;
        case 0: ptz->bal = 0; (*pt)->esq->bal = 0; break;
        case 1: ptz->bal = 0; (*pt)->esq->bal = -1; break;
        }
        (*pt)->bal = 0;
        return 1;
    }
}
int insert_AVL(NO **pt,int chave){ //0- no add,1- add e altura alterou, 2-add e altura n alterou
  if(*pt == NULL){ //tree vazia
    *pt = malloc(sizeof(NO));
    (*pt)->chave = chave; (*pt)->bal = 0; (*pt)->dir = NULL; (*pt)->esq = NULL;
    return 1;
  }else if(chave == (*pt)->chave){//ja existe
      return 0;
  }else{ //continua procurando
    int h;
    if(chave < (*pt)->chave){
      h = insert_AVL(&(*pt)->esq,chave);
      if(h == 1){
        switch (((*pt)->bal)){
          case 1:{(*pt)->bal = 0; return 2; 
          }case 0:{(*pt)->bal = -1;return 1;
          }case -1:{(rotate_right(pt)); return 2;}
        }
      }else if(h == 2){
        return 2;
      }
    }else{
    h = insert_AVL(&(*pt)->dir,chave);
    if(h == 1){
      
      switch ((*pt)->bal){
        case -1:{(*pt)->bal = 0; return 2; 
        }case 0:{(*pt)->bal = 1; return 1; 
        }case 1:{(rotate_left(pt)); return 2;}
      }
    }else if(h == 2){
        return 2;
    }
  }
  return 0;
  }
}
int seach_NO(NO *pt,int chave){ //0 não existe e 1 existe
  if(pt == NULL){
    return 0;
  }else if(chave == pt->chave){
    return 1;
  }else if(chave < pt->chave){
    return seach_NO(pt->esq,chave);
  }else{
    return seach_NO(pt->dir,chave);
  }
}
void print_preorder(NO *pt){
    if (pt == NULL)
        return;
    printf("\n%i : %i",pt->chave,pt->bal);
    print_preorder(pt->esq);
    print_preorder(pt->dir);
}
int height_tree(NO *pt,int height){//retorna altura do NO
  if(pt != NULL){
    int left = height_tree(pt->esq,height+1);
    int right = height_tree(pt->dir,height+1);
    if(right > left){
      return right;
    }
    return left;
  }else{
    return height;
  }
}
int test_avl(NO *pt) {//testa se a tree é avl
    if (pt == NULL) {
        return 1;
    }else{
      if(pt->dir || pt->esq){
        if(pt->bal == ((height_tree(pt->dir,0))- (height_tree(pt->esq,0)))){
          return (test_avl(pt->esq) && test_avl(pt->dir));
        }
        return 0;
      }else{
        if(!(pt->bal)){
          return 1;
        }
        return 0;
      }
    }
}
int count_NO(NO *pt) {//conta os nos
    if(pt == NULL) {
      return 0;
    }else if(pt->dir || pt->esq){ //!= NULL
      return (1 + (count_NO(pt->esq) + count_NO(pt->dir)));
    }
    return 1;
}
void destroy_tree(NO *pt){//deleta a tree
    if (pt == NULL)
      return;
    destroy_tree(pt->esq);
    destroy_tree(pt->dir);
    free(pt); pt = NULL;
}
int balance_remove(NO **pt,int side){//1 alterou alt - 0 não alterou alt
  if(side == 0){ //remove left
    switch ((*pt)->bal){
    case -1:{(*pt)->bal = 0; return 1;}
    case  0:{(*pt)->bal = 1 ; return 0;}
    case 1:{return (rotate_left_remove(pt));}
    }
  }else{ //remove right
    switch ((*pt)->bal){
    case 1:{(*pt)->bal = 0; return 1;}
    case 0:{(*pt)->bal =-1; return 0;}
    case -1:{return (rotate_right_remove(pt));
      }
    }
  }
}
int logica_remove(NO **pt,int chave){//1 alterou alt/removeu - 0 não alterou alt
  NO *aux; 
  if(((*pt)->esq == NULL) && ((*pt)->dir == NULL)){
    free((*pt)); (*pt) = NULL; 
    return 1;
  }else if((*pt)->dir != NULL){
    if((*pt)->dir->esq == NULL){
      (*pt)->dir->esq = (*pt)->esq;
      (*pt)->dir->bal = (*pt)->bal;
      aux = (*pt);
      (*pt) = (*pt)->dir;
      free((aux)); aux = NULL;
      return (balance_remove(pt,1));
    }else{
      aux = (*pt)->dir;
      NO *pais; 
      while (aux->esq != NULL){
        pais = aux;
        aux = aux->esq;
      }
      (*pt)->chave = aux->chave;
      if(remove_AVL(&((*pt)->dir),aux->chave)){
        return balance_remove(pt,1);
      }
  }
  }else{
    aux = (*pt);
    (*pt) = (*pt)->esq;
    free(aux); aux = NULL;
    return 1;
  }
  return 0;
}
int remove_AVL(NO **pt,int chave){ //1 alterou alt - 0 não alterou alt
  if((*pt)){
    if((*pt)->chave == chave){
      return (logica_remove(pt,chave));
    }else if((chave < (*pt)->chave)){
      if(remove_AVL(&((*pt)->esq),chave)){
        return (balance_remove(pt,0));
      }return 0;
    }else{
      if(remove_AVL(&((*pt)->dir),chave)){
        return (balance_remove(pt,1));
      }
    }
  }
  return 0;
}