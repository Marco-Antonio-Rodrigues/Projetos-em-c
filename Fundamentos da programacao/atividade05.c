// 05. Escreve um programa que sorteio, aleatoriamente, 10 números e armazene estes em um vetor.
// Em seguida, o usuário digita um número e seu programa em C deve acusar se o número digitado 
// está no vetor ou não. Se estiver, diga a posição que está.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 5

int main(){

    int vetor[MAX],c,numero_digitado,igual = 0,local;
    srand((unsigned)time(NULL));

    for(c = 0;c < MAX;c++ ){
        vetor[c] = rand()%MAX;
    }

    printf("\nDigite um numero:");
    scanf("%i",&numero_digitado);

    for(c = MAX -1;c >= 0;c--){
        if (vetor[c] == numero_digitado){
            igual = 1;
            printf("Valor igual na posicao %i",c);
        }
    }
    if (igual == 0){
        printf("nao tem valor igual");
    }

    for (c = 0;c < MAX;c++){
        printf("\n%i",vetor[c]);
    }


return 0;
}