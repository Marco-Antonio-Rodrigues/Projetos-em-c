#include <stdio.h>

int main()
{
    float a, b, c, d,e,f, x;

    printf("Digite a: ");
    scanf("%f", &a);
    printf("Digite b: ");
    scanf("%f", &b);
    printf("Digite c: ");
    scanf("%f", &c);
    printf("Digite d: ");
    scanf("%f", &d);
    printf("Digite e: ");
    scanf("%f", &e);
    printf("Digite f: ");
    scanf("%f", &f);

    x = pow((a + 3 * b), (c / d));
    printf("\nx = %f", x);

    x = (a + b * c)/(d - e/f);
    printf("\nx = %f", x);

    x = pow(a,b)-(pow(c,d)+e);
    printf("\nx = %f", x);

    x = pow(a,pow(b,pow(c,d)));
    printf("\nx = %f", x);

    return 0;
}