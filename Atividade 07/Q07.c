#include <stdio.h>

int main(){
    
    int classe;
    float c,vf,tarifa_a,tarifa_b,tarifa_c,icms;

    tarifa_a = 1.0;
    tarifa_b = 0.8;
    tarifa_c = 0.5;

    printf("Qual a classe consumidora? ");
    printf("\n1- a\t2- b\t3- c\n:");
    scanf("%i",&classe);

    printf("\nQual o seu consumo?\n:");
    scanf("%f",&c);

    if (classe == 1){
    vf = c *  tarifa_a;
    }
    else if  (classe == 2){
    vf = c *  tarifa_b;
    }
    else{
    vf = c *  tarifa_c;
    }

    icms = 0.3 * vf;
    vf = vf + icms;

    printf("\nValor a pagar: %f",vf);

    return 0;
}