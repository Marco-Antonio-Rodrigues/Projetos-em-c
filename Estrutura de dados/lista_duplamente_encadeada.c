#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No * prox;
    struct No * ant;
}No;

No * inicio = NULL;
No * fim = NULL;
int tam = 0;

void adicionar(int valor, int pos){
    if(pos>= 0 && pos<= tam){
        No * novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;
    
        if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ // posicao é 0 - inicio! :D
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        }else if(pos == tam){ //posicao é tam - fim! :D
            fim->prox = novo;
            novo->ant = fim;
            fim = novo;
        }else{ //no meio! :'(
            //pedaco problematico!!!!!
            No * aux = inicio;
            for(int i = 0; i< pos - 1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->ant = aux;
            novo->prox->ant = novo;
        }
        tam++;
    }
}

int remover(int pos){
    if(pos>= 0 && pos < tam){
        No *lixo;
        if(tam == 1){
            lixo = inicio;
            inicio = NULL;
            fim = NULL;
            free(lixo);
        }else if(pos == 0){
            lixo = inicio;
            inicio = inicio->prox;
            inicio->ant = NULL;
            free(lixo);
            
        }else if(pos == tam-1){
            
            lixo = fim;
            fim->ant->prox = NULL;
            fim = fim->ant;
            free(lixo);
            
            //DICA PQ EU NAO APAGUEI! :D
            /*No * aux = inicio;
            for(int i=0; i< pos - 1; i++){
                aux = aux->prox;
            }
            aux->prox = NULL;
            lixo = fim;
            fim = aux;*/
        }else{
            No * aux = inicio;
            for(int i=0; i< pos; i++){
                aux = aux->prox;
            }
            No *lixo = aux;
            aux = aux->ant;
            aux->prox = lixo->prox;//erro comeca aqui
            lixo->prox->ant = lixo->ant; 
            free(lixo);
        }
        tam--;
    }

    return 0;
}

void imprimir(){
    No * aux = inicio;
    for(int i = 0; i<tam; i++){
        printf("Valor = %d\n", aux->valor );
        aux = aux->prox;
    }
}

int main(){
    adicionar(10,0);
    adicionar(15,1);
    adicionar(20,2);
    adicionar(25,3);
    remover(1);
    imprimir();
return 0; 
}
