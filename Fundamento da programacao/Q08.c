#include <stdio.h>

void main(){
    
    int p1[2],p2[2];
    float d;

    printf("digite as coordenadas do ponto p1\nX: ");
    scanf("%i",&p1[0]);
    printf("Y: ");
    scanf("%i",&p1[1]);

    printf("\ndigite as coordenadas do ponto p2\nX: ");
    scanf("%i",&p2[0]);
    printf("Y: ");
    scanf("%i",&p2[1]);

    d = pow(pow(p2[0]-p1[0],2) + pow(p2[1]-p1[1],2),0.5);

    printf("Distancia entre os pontos: %f",d);

    return;
}