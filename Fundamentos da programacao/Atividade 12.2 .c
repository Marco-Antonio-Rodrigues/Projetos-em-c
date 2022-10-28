// 2a questão: Faça uma STRUCT chamada Aniversário que tenha uma data da seguinte forma:
// int dia;
// char[20] mes;
// int ano;
// Nessa questão além de você criar essa STRUCT, vai permitir a pessoa inserir e depois 
// mostrar a data de aniversário.

#include <stdio.h>

int main(){

    struct anivesario{
        int dia;
        char mes[20];
        int ano;
    };

    struct anivesario data;

    printf("Diga o dia do seu anivesario:");
    scanf("%i",&data.dia);
    printf("Diga o mes do seu anivesario(escrito):");
    scanf("%s",data.mes);
    printf("Diga o ano do seu anivesario:");
    scanf("%i",&data.ano);

    printf("\nSeu anivesario e dia %i de %s de %i\n",data.dia,data.mes,data.ano);


return 0;
}
