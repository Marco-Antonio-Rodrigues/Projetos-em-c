#include <stdio.h>

int main()
{

    int valor, s, c100, c50, c20, c10, c5, c2, c1;

    printf("digite um valor para saque(notas disponiveis 100,50,20,10,5,2): ");
    scanf("%i", &valor);

    while (valor == 0)
    {
        printf("O valor nao pode ser zero!");
        break;
    }

    s = 100;
    c100 = 0;
    while ((valor >= 100) && (s <= valor))
    {
        s = s + 100;
        c100 = c100 + 1;
    }
    valor = valor - (100 * c100);
    printf("\n%i notas de 100\n", c100);

    s = 50;
    c50 = 0;
    while ((valor >= 50) && (s <= valor) && (valor != 51))
    {
        s = s + 50;
        c50 = c50 + 1;
    }
    valor = valor - (50 * c50);
    printf("%i notas de 50\n", c50);

    s = 20;
    c20 = 0;
    while ((valor >= 20) && (s <= valor) && (valor != 21))
    {
        s = s + 20;
        c20 = c20 + 1;
    }
    valor = valor - (20 * c20);
    printf("%d notas de 20\n", c20);

    s = 10;
    c10 = 0;
    while ((10 <= valor) && (valor != 13) && (s <= valor) && (valor != 11) && (valor != 21))
    {
        s = s + 10;
        c10 = c10 + 1;
    }
    valor = valor - (10 * c10);
    printf("%d notas de 10\n", c10);

    s = 5;
    c5 = 0;
    while ((valor >= 5) && (c5 != 1) && (valor != 6) && (valor != 8))
    {
        s = s + 5;
        c5 = c5 + 1;
    }
    valor = valor - (5 * c5);
    printf("%d notas de 5\n", c5);

    s = 2;
    c2 = 0;
    while ((valor >= 2) && (s <= valor))
    {
        s = s + 2;
        c2 = c2 + 1;
    }
    valor = valor - (2 * c2);
    printf("%i notas de 2\n", c2);

    while (valor == 1)
    {
        c1 = 0;
        printf("\nNao sera possivel o saque de 1 real por conta da falta de cedulas, o restante sera sacado.");
        c1 = c1 + 1;
        printf("\nrestante na conta: R$ %i,00\n", c1);
        break;
    }
    return 0;
}
