// Marco Antonio Rodrigues Gomes de Souza- 511354
#include <stdio.h>
#include <stdlib.h>
#include "No.h"

NO *inicio;
int tam = 0;

//function soma
int soma_total_filhotes = 0;
int *somador = &soma_total_filhotes;
int backup = 0; //serve como backup pro tam

void add (int id, int sexo, int num_filhotes){
    NO *novo = malloc (sizeof(NO));
    novo->id = id;
    novo->sexo = sexo;
    novo->num_filhotes = num_filhotes;
    if(tam == 0){
        novo->prox = novo;
        novo->ant = novo;
        inicio = novo;
    }else{
        novo->prox = inicio;
        novo->ant = inicio->ant;
        inicio->ant->prox = novo;
        inicio->ant = novo;
    }
    tam++;
}


void remover(int id){
    NO *aux = inicio;
    for(int i=0; i<tam; i++){
        if(aux->id == id){
            break;
        }else{
            aux = aux->prox;
        }
    }
    if(aux->id == id){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        if(aux == inicio){
            inicio = aux->prox;
        }
        free(aux);
        tam--;
    }else{
        printf("Canguru não encontrado! \n");
    }
}

int soma (){//declarado na lib
    if ((tam == 0) && (backup==0)){ //retorna -1 se a lista esta vazia
        return -1;
    }else if((tam != 0) && (backup==0) && (*somador != 0)){//faz com que quando a soma for utilizada multiplas vezes nao acumule a soma
        *somador = 0;
        soma();
    }else if(tam != 0){// confere se ja chegou no final
        *somador = *somador + inicio->num_filhotes;
        inicio = inicio->prox;
        tam--;
        backup++;
        soma();
    }else{ //retorna a soma se tudo deu certo
        tam = backup;
        backup = 0;
        return *somador;
    }
}

void imprimir(){
    NO *aux = inicio;
    for(int i=0; i<tam; i++){
        printf("Caguru: %d \n", aux->id);
        aux = aux->prox;
    }
}

int main(){

    add(1,1,2);
    add(2,1,1);
    add(3,0,0);
    add(4,1,2);
    add(5,0,0);
    add(6,0,1);
    imprimir();
    printf("\nsoma total: %i",soma());

    return 0;
}
