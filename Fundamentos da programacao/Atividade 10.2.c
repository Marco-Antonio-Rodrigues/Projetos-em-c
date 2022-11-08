// Por: Marco Antonio Rodrigues Gomes de Souza

// 2.Faça um programa que decida se duas strings lidas do teclado
// são palíndromas mútuas, ou seja, se uma é igual à outra quando
// lida de traz para frente.

#include<stdio.h>

int main(){

    char palavra1[20000],palavra2[20000];
    int numero_de_caracteres=0,i,c,igual=0;

    printf("Digite a primeira palavra: ");
    scanf("%s",palavra1);

    printf("Digite a segunda palavra: ");
    scanf("%s",palavra2);

    while (palavra1[numero_de_caracteres] !='\0'){
        numero_de_caracteres++;
    }

    for(i=0;i<numero_de_caracteres;i++){
        for(c=numero_de_caracteres-1;c>=0;c--){
            if (palavra1[i] == palavra2[c]){
                igual++;
            }
        }   
    }

    printf("\n");

    if (igual == numero_de_caracteres){
        printf("Sao polindromas mutuas\n");
    }
    else{
        printf("Nao sao polindromas mutuas\n");
    }

return 0;
}