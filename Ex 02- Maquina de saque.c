#include <stdio.h>

// Por: Marco Antonio Rodrigues Gomes de Souza
// Esse codigo simula uma maquina de sacar dinheiro, na qual ele
// recebe uma entrada do valor que o usuario quer sacar e tem como saida o numero de cedulas
// que foram sacadas e se sobrar algo ele informar ao usuario.
int main(){

    // variaveis
    int numerodigitado, nota100, nota50, nota20, nota10, nota5, nota2;
    nota100 =0;
    nota50 =0;
    nota20 =0;
    nota10 =0;
    nota5 =0;
    nota2 =0;

    // entrada de dados
    printf("digite um valor para saque(notas disponiveis 100,50,20,10,5,2): ");
    scanf("%i", &numerodigitado);

    // algoritmo
    if(numerodigitado >= 100){
        nota100 = numerodigitado/100;
        numerodigitado = numerodigitado % 100;
        printf("\nnotas de R$100,00: %i",nota100);
    }
    if(numerodigitado >= 50){
        nota50 = numerodigitado/50;
        numerodigitado = numerodigitado % 50;
        printf("\nnotas de R$50,00:  %i",nota50);
    }
    if(numerodigitado >= 20){
        nota20 = numerodigitado/20;
        numerodigitado = numerodigitado % 20;
        printf("\nnotas de R$20,00:  %i",nota20);
    }
    if(numerodigitado >= 10){
        nota10 = numerodigitado/10;
        numerodigitado = numerodigitado % 10;
        printf("\nnotas de R$10,00:  %i",nota10);
    }
    if(numerodigitado >= 5){
        nota5 = numerodigitado/5;
        numerodigitado = numerodigitado % 5;
        printf("\nnotas de R$5,00:   %i",nota5);
    }
    if(numerodigitado >= 2){
        nota2 = numerodigitado/2;
        numerodigitado = numerodigitado % 2;
        printf("\nnotas de R$2,00:   %i",nota2);
    }
    if(numerodigitado >= 1){
        printf("\n por falta de cedulas compativeis faltou R$%i,00 para o saque.",numerodigitado);
    }
    return 0;
}

// exemplo de execucao:

// digite um valor para saque(notas disponiveis 100,50,20,10,5,2): 187

// notas de R$100,00: 1
// notas de R$50,00:  1
// notas de R$20,00:  1
// notas de R$10,00:  1
// notas de R$5,00:   1
// notas de R$2,00:   1
