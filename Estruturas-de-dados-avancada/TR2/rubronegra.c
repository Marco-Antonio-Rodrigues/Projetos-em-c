#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int chave;
	int cor;//1 == red e 0 == black
	struct no *esq;
	struct no *dir;
  struct no *pai;
}NO;

NO* ptnull;
NO* raiz;
void left_rotate(NO *z);
void right_rotate(NO *z);
void rota_RN(NO *z);
int insertRN(NO **ptraiz,NO* z);
NO *create_NO(int chave);
void print_preorder(NO *pt);
int heightNegra(NO* pt);
int checkRN(NO* raiz);
int countNO(NO *pt);
NO *seachNO(NO *pt, int chave);
NO *sucessor(NO *z);
void RotaRemoverRN(NO *x);
void removeRN(NO *z);
void destroy_tree(NO *pt);

int main(){
  ptnull = malloc(sizeof(NO)); ptnull->cor = 0; ptnull->esq = ptnull->dir = ptnull;
  for(int j = 0;j<1;j++){//quant RNs
    int i = 0;
    raiz = ptnull;
    while (i<100){//quant nos por RN
      if(insertRN(&raiz,create_NO(rand()%100000))){
        i++;
      }
    }
    printf("\ninfo tree %i: quant. nos? %i ,é RN? %i ",j,countNO(raiz),checkRN(raiz));
    
    for(i = 0;i<10;i++){//quant remocao
      removeRN(seachNO(raiz,raiz->chave));
    }
    printf("\nremovendo 10nos... quant. nos? %i ,é RN? %i \n",countNO(raiz),checkRN(raiz));
    destroy_tree(raiz);
  }
  return 0;
}

NO *create_NO(int chave){
  NO *new = malloc(sizeof(NO));
  new->chave = chave;
  new->cor = 1;
  new->esq = new->dir = ptnull;
  return new;
}

void left_rotate(NO *z){
    NO *aux = z->dir;
    z->dir = aux->esq;
    if (aux->esq != ptnull){
        aux->esq->pai = z;
    }
    aux->pai = z->pai;
    if (z->pai == ptnull){
        raiz = aux;
    }else{
        if (z == z->pai->esq){
            z->pai->esq = aux;
        }else{
            z->pai->dir = aux;
        }
    }
    aux->esq = z;
    z->pai = aux;

}

void right_rotate(NO *z){
  NO *aux = z->esq;
  z->esq = aux->dir;

  if (aux->dir != ptnull)
  {
      aux->dir->pai = z;
  }

  aux->pai = z->pai;
  if (z->pai == ptnull){
      raiz = aux;
  }else{
      if (z == z->pai->dir){
          z->pai->dir = aux;
      }else{
          z->pai->esq = aux;
      }
  }

  aux->dir = z;
  z->pai = aux;
}

void rota_RN(NO *z){
  NO *y;
  while (z->pai->cor == 1){
      if (z->pai == z->pai->pai->esq){
          y = z->pai->pai->dir;
          if (y->cor == 1){
              z->pai->cor = 0;
              y->cor = 0;
              z->pai->pai->cor = 1;
              z = z->pai->pai;
          }else{
              if (z == z->pai->dir){
                  z = z->pai;
                  left_rotate(z);
              }
              z->pai->cor = 0;
              z->pai->pai->cor = 1;
              right_rotate(z->pai->pai);
          }
      }else{
          y = z->pai->pai->esq;
          if (y->cor == 1){
              z->pai->cor = 0;
              y->cor = 0;
              z->pai->pai->cor = 1;
              z = z->pai->pai;
          }else{
              if (z == z->pai->esq)
              {
                  z = z->pai;
                  right_rotate(z);
              }
              z->pai->cor = 0;
              z->pai->pai->cor = 1;
              left_rotate(z->pai->pai);
          }
      }
  }
  raiz->cor = 0;
}

int insertRN(NO** ptraiz, NO* z) {
  NO* y = ptnull;
  NO* pt = *ptraiz;
  while (pt != ptnull){
    y = pt; 
    if (z->chave == pt->chave) {
        y = NULL;
        pt = ptnull;
    } else {
        if(z->chave < pt->chave){
            pt = pt->esq;
        }else{
            pt = pt->dir;
        }
    }
  }
  if (y != NULL) {
      z->pai = y;
      if (y == ptnull) {          
          *ptraiz = z;
      }else {
        if (z->chave < y->chave) {
            y->esq = z;
        } else {
            y->dir = z;
        }
      }
      z->esq = z->dir = ptnull;
      z->cor = 1;
      rota_RN(z);
      return 1;
  }
  return 0;
}

void RotaRemoverRN(NO *x){
NO *w;
  while ((x != raiz) && (x->cor != 1)){
      if (x == x->pai->esq){
          w = x->pai->dir;
          if(w->cor == 1){
              x->pai->cor = 1;
              w->cor = 0;
              left_rotate(x->pai);
              w = x->pai->dir;
          }
          if ((w->dir->cor == 0) && (w->esq->cor == 0)){
              w->cor = 1;
              x = x->pai;
          }else{
              if (w->dir->cor == 0){
                  w->esq->cor = 0;
                  w->cor = 1;
                  right_rotate(w);
                  w = x->pai->dir;
              }
              w->cor = x->pai->cor;
              x->pai->cor = 0;
              w->dir->cor = 0;
              left_rotate(x->pai);
              x = raiz;
          }
      }else{
          w = x->pai->esq;

          if(w->cor == 1){
              x->pai->cor = 1;
              w->cor = 0;
              right_rotate(x->pai);
              w = x->pai->esq;
          }
          if ((w->esq->cor == 0) && (w->dir->cor == 0)){
              w->cor = 1;
              x = x->pai;
          }else{
              if (w->esq->cor == 0){
                  w->dir->cor = 0;
                  w->cor = 1;
                  left_rotate(w);
                  w = x->pai->esq;
              }
              w->cor = x->pai->cor;
              x->pai->cor = 0;
              w->esq->cor = 0;
              right_rotate(x->pai);
              x = raiz;
          }
      }
  }
  x->cor = 0;
}

//faz pai de U ser pai de v
void moverPai(NO *u,NO *v){
  if(u->pai == ptnull){
  raiz = v;
  } else{
    if(u == u->pai->esq){
      u->pai->esq = v;
    }else{
      u->pai->dir = v;
    }
  }
  v->pai = u->pai;
}

void removeRN(NO *z){
  if(z != ptnull){
    NO *y = z; NO *x;
    int corOriginal = y->cor;
    if(y->esq == ptnull){
      x = z->dir;
      moverPai(z,z->dir);
    }else if(y->dir == ptnull){
      x = z->esq;
      moverPai(z,z->esq);
    }else{
      y = sucessor(z); corOriginal = y->cor;
      x = y->dir;
      if(y->pai != z){
        moverPai(y,x);
        y->dir = z->dir;
        y->dir->pai = y;
      }else{
        x->pai = y;
      }
      moverPai(z,y);
      y->esq = z->esq;
      y->esq->pai = y;
      y->cor = z->cor;
    }
    if(corOriginal == 0){
      RotaRemoverRN(x);
    }
  }
  raiz->cor = 0;
}

void print_preorder(NO *pt){
    if (pt == ptnull)
      return;
    printf("\n%i : %i",pt->chave,pt->cor);
    print_preorder(pt->esq);
    print_preorder(pt->dir);
}

int checkRN(NO* pt) {
  
  if (pt == ptnull) return 1;

  if (pt->cor != 0 && pt->cor != 1){ return 0;}

  if (pt->cor == 1 && pt->pai == ptnull){; return 0;}
  
  if (pt->cor == 1 && (pt->esq->cor == 1 || pt->dir->cor == 1)){ return 0;}
  
  int heightLeft = heightNegra(pt->esq);
  int heightRight = heightNegra(pt->dir);
  if (heightLeft == -1 || heightRight == -1 || heightLeft != heightRight) {
    return 0;
  }

  int subArvoreEsquerda = checkRN(pt->esq);
  int subArvoreDireita = checkRN(pt->dir);
  
  return (subArvoreEsquerda && subArvoreDireita);
}

int heightNegra(NO* pt) {
  if (pt == ptnull) return 0;
  
  int caminhoEsquerda = heightNegra(pt->esq);
  int caminhoDireita = heightNegra(pt->dir);

  if (caminhoEsquerda == -1 || caminhoDireita == -1 || caminhoEsquerda != caminhoDireita) {
    return -1;
  }
  return caminhoEsquerda + (pt->cor == 0); 
}

int countNO(NO *pt){
  if (pt == ptnull) return 0;

  int countLeft = countNO(pt->esq);
  int countRight = countNO(pt->dir);
  return (countLeft + countRight + 1);
}

NO *seachNO(NO *pt, int chave){
  if(pt != ptnull){
    if(pt->chave == chave){
      return pt;
    }else{
      if(chave > pt->chave){
        return seachNO(pt->dir,chave);
      }else{
        return seachNO(pt->esq,chave);
      }
    }
  }
  return ptnull;
}

NO *sucessor(NO *z){
  if(z->dir != ptnull){
    z = z->dir;
    while(z->esq != ptnull){
      z = z->esq;
    }
  }
  return z;
}

void destroy_tree(NO *pt){
    if (pt == ptnull)
      return;
    destroy_tree(pt->esq);
    destroy_tree(pt->dir);
    free(pt); pt = NULL;
}