#include <stdio.h>

int main(){

// Por: Marco Antonio Rodrigues Gomes de Souza
// Descrição: esse programa converte base binaria para decimal e vice-versa.

// variaveis usadas
int decimalentrada,binariosaida[20],resto,contador, menu,numero_unico,multiplicador, decimal_saida;
char str[20],binario_entrada[20],ponteiro[20];
menu = 0;

//laço principal na qual roda todo o programa, ao sair dele o programa é finalizado(quando menu == 3).
while (menu != 3){


    // Menu do programa.
    printf("\nDigite 1 para converter de dec->bin.\nDigite 2 para converter de bin->dec.\nDigite 3 para sair.\n:");
    scanf("\n%i",&menu);

    // se menu == 1 ele entra nesse laço, recebe a entrada converte e após a saída de dado,
    // menu = 0 saindo do laço e voltando pro menu principal.
    while (menu == 1){

        contador = 0;
        printf("\nEscreva o numero para a converter: ");
        scanf("%i",&decimalentrada);

        while(decimalentrada != 0){
            resto = decimalentrada%2;
            decimalentrada = decimalentrada/2;
            binariosaida[contador]= resto;
            contador = contador + 1;
        }
        printf("\n////////////////////////////////\nEm binario_entrada fica: ");
        while (contador > 0){
            contador = contador - 1;
            printf("%i",binariosaida[contador]);
            
        }
        printf("\n////////////////////////////////");
        menu = 0;
    }

    // se menu == 2 ele entra nesse laço, recebe a entrada converte e após a saída de dado,
    // menu = 0 saindo do laço e voltando pro menu principal.
    while(menu == 2){

        printf("\nDigite para converter de bin->dec: ");
        scanf("%s",binario_entrada);

        contador = strlen(binario_entrada);
        multiplicador = 1;
        decimal_saida = 0;

        while (contador > 0){
            contador = contador - 1;
            ponteiro[0] =binario_entrada[contador];
            strcpy(str, ponteiro);
            numero_unico = atoi(str);
            decimal_saida = decimal_saida + (numero_unico*multiplicador);
            multiplicador = multiplicador*2;
        }
        printf("\n////////////////////////////////");
        printf("\nEm decimal_saida fica: %i",decimal_saida);
        printf("\n////////////////////////////////");
        menu = 0;
    }
}

return 0;
}