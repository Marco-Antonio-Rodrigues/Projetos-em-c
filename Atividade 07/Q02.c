#include <stdio.h>
#include <math.h>

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

    x = sqrt(pow(a,2) - 3*b + 1)/(5*(a+b));
    printf("\nx = %f", x);

    x = -b + sqrt(pow(b,2)-4*a*c)/(2*a);
    printf("\nx = %f", x);

    x = (a + b/c)/(d - e/f);
    printf("\nx = %f", x);

    x = pow((sqrt((pow(a,6)-1)-(e/(a+b)))),3);
    printf("\nx = %f", x);

    return 0;
}