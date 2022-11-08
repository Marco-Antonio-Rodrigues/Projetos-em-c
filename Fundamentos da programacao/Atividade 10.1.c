// Por: Marco Antonio Rodrigues Gomes de Souza

// 1.Faça um programa que leia o nome do usuário e mostre
// o nome de traz para frente.

#include<stdio.h>

int main(){

    char nome[20000];
    int numero_de_caracteres=0,i;

    printf("Digite seu nome: ");
    scanf("%[^\n]",nome);

    while (nome[numero_de_caracteres] !='\0'){
        numero_de_caracteres++;
    }

    printf("\nseu nome inverso: ");

    for(i=numero_de_caracteres-1;i>=0;i--){
        printf("%c",nome[i]);
    }
    printf("\n");
    
return 0;
}
