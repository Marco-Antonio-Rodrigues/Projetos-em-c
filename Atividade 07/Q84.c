#include <stdio.h>

int fat(int n){
    if (n == 0)
        return 1;  
    return n * fat(n-1);
}

int main(){

    int fator;

    printf("Digite o numero para saber seu fatorial: ");
    scanf("%i",&fator);
    printf("\nFatorial de %i = %i",fator,fat(fator));

    return 0;
}