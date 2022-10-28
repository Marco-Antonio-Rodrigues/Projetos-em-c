// 1a questão: Faça um programa que utilize SWITCH com as seguintes opções:
// Digite 1 para curso de ES
// Digite 2 para curso de CC
// Ou seja, utilizando switch ao digitar 1 aparecerá a mensagem:"você escolheu Engenharia de Software".
// Ao digitar 2 aparecerá a mensagem:"você escolheu Ciência da Computação".
#include <stdio.h>

int main(){

    int resposta;
    printf("=-=-=-=-=-=-=| Escolha seu Curso |=-=-=-=-=-=-=");
    printf("\nDigite 1 para ES");
    printf("\nDigite 2 para CC\n:");
    scanf("%i",&resposta);

    switch (resposta){
    case 1:
        printf("voce escolheu Engenharia de Software");
        break;
    case 2:
        printf("voce escolheu Ciencia da Computacao");
        break;
    
    default:
        printf("Erro");
        break;
    }

return 0;
}
