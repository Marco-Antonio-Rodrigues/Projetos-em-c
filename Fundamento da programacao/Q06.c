#include <stdio.h>

int main(){
    
    float peso,quantidade_racao;
    int dias;

    printf("Digite a quantidade de racao(kg): ");
    scanf("%f", &peso);
    printf("quanto cada gato come ao dia(G): ");
    scanf("%f", &quantidade_racao);
    peso = peso*1000;
    quantidade_racao = quantidade_racao * 2;
    dias = peso/quantidade_racao;
    printf("A racao e suficiente para %i dias.",dias);

    return 0;
}