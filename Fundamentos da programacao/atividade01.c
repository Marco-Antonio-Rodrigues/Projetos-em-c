// 00. Crie um programa em C que peça 10 números,
// armazene eles em um vetor e diga qual elemento é o maior, e seu valor.

#include<stdio.h>

#define MAX 10

int main(){

    int vetor[MAX],maior_numero = 0,c,numero_digitado,elemento;

    for (c = 0;c < MAX; c++){
        scanf("%i",&numero_digitado);
        vetor[c] = numero_digitado;
        if (numero_digitado > maior_numero){
            maior_numero = numero_digitado;
            elemento = c;
        }
    }

    for (c = MAX -1;c >= 0; c--){
        printf("\n%i",vetor[c]);
    }

    printf("\nO maior numero digitado foi %i no elemento %i",maior_numero,elemento);
return 0;
}