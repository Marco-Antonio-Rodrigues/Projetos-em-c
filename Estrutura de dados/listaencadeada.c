#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No * prox;
}No;

No * inicio = NULL;
No * fim = NULL;
int tam = 0;

void adicionar(int valor, int pos){
    if(pos>= 0 && pos<= tam){
        No * novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = NULL;
    
        if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ // posicao é 0 - inicio! :D
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){ //posicao é tam - fim! :D
            fim->prox = novo;
            fim = novo;
        }else{ //no meio! :'(
            //pedaco problematico!!!!!
            No * aux = inicio;
            for(int i = 0; i< pos - 1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }
}


int remover(int pos){
    No *removido = inicio;
    No *aux;
    if(pos == 0){
        inicio = inicio->prox;
    }else{
        for(int i=0;i<pos;i++){
            aux = removido;
            removido = removido->prox;
        }
        aux->prox = removido->prox;
    }
    tam--;
    return removido->valor;
}

void imprimir(){
    if(tam == 0){
        printf("erro, lista vazia!\n");
    }else{
        No * aux = inicio;
        for(int i = 0; i<tam; i++){
            printf("Valor = %d\n", aux->valor );
            aux = aux->prox;
        }
    }    
}


int main(){
    adicionar(10,0);
    adicionar(15,1);
    adicionar(20,2);
    adicionar(18,3);
    adicionar(35,4);
    remover(4);
    imprimir();
return 0;
    
}
