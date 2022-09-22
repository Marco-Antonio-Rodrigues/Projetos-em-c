#include <stdio.h>

void conversor(int numero){
    if(numero == 0){
        printf("%i",numero);
        return;
    }
    else{
        conversor(numero/2);
        printf("%i",numero%2);
    }
}
int main(){
    int numero_digitado;
    printf("digite um numero de 1 a 31: ");
    scanf("%i",&numero_digitado);
    
    printf("Resultado da conversao: ");
    conversor(numero_digitado);
 return 0;
}