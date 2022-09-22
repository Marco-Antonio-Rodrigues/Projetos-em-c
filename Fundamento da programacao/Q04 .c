#include <stdio.h>

int main()
{
    float valor,n,a,prestacao,i;

    a = 0.01; //taxa de 1% ao mês

    printf("Digite o valor da nota fiscal: ");
    scanf("%f", &valor);
    printf("Digite numero de prestacoes: ");
    scanf("%f", &n);
    printf("Digite o numero da prestacao que voce quer consultar: ");
    scanf("%f", &i);

    prestacao = (valor/n)*pow(1 + a,i);
    printf("%f",prestacao);

    
    return 0;
}