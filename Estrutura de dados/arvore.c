#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

NO* busca(int x, NO* aux){
    if(aux == NULL){
        return NULL; //vazia
    }else if(x == aux->chave){
        return aux; //encontrei :D
    }else if(x<aux->chave){ //buscar no lado esq
        if(aux->esq != NULL){
            return busca(x, aux->esq);
        }else{//esq esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }else{//buscar no lado dir
        if(aux->dir != NULL){
            return busca(x, aux->dir);
        }else{//dir esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
}


void add(int x){
    NO* resp = busca(x, raiz);
    if(resp == NULL || resp->chave != x){// vazia ou eu posso adicionar
        NO* novo = malloc (sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(resp == NULL){ //add na raiz
            raiz = novo;
        }else{
            if(x < resp->chave){
                resp->esq = novo;
            }else{
                resp->dir = novo;
            }
        }
    }else{//nao posso deixar add novamente pq neste caso
        //havera chaves duplicadas
        printf("Add inválida. Chave duplicada");
    }
    
}

void imprime(NO *aux){
    if(aux == NULL){
        return;
    }else{
        printf("\n%i",aux->chave);
    }
}

void pre_ordem(NO* aux){
   if (aux == NULL){
    return;
   }else{
    printf("\n%d", aux->chave); 
    pre_ordem(aux->esq);
    pre_ordem(aux->dir);
   }
}

void in_ordem(NO* aux){
    if (aux == NULL) return;
    in_ordem(aux->esq);
    printf("\n%d", aux->chave); 
    in_ordem(aux->dir);
}

void pos_ordem(NO* aux){
    if (aux == NULL) return; 
    pos_ordem(aux->esq);
    pos_ordem(aux->dir);   
    printf("\n%d", aux->chave); 
}


int main(){
    add(11);
    add(8);
    add(12);
    add(7);
    add(9);
    add(10);
    in_ordem(raiz);
    pre_ordem(raiz);
    pos_ordem(raiz);
    return 0;
}
