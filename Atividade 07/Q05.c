#include <stdio.h>

int main()
{
    float peso, altura, imc;

    printf("Vamos calcular seu IMC!\n=-=-=-=-=-=-=--=-=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Digite o seu peso em KG: ");
    scanf("%f", &peso);
    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    printf("IMC: %f", imc);

    return 0;
}