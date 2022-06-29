// Por: Marco Antonio Rodrigues Gomes de Souza
// Descrição: Cria uma matriz sem repetir valores e de qualquer ordem.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(){

    int tamanho; //Ordem da matriz

    printf("Digite a ordem da matriz: ");
    scanf("%i",&tamanho);

    int matriz[tamanho][tamanho],i,j,w,k,igual = 0,teste;

    printf("\nBarra de carregamento (total de %i barras):\n (",tamanho*tamanho); // a cada número adicionado a barra aumenta um.

    // Estrutura de criação da matriz, a cada número gerado o algoritmo faz a validação 
    // para validar se não há valores iguais, se tiver ele gera outro e repete o processo, 
    // se não ele adiciona e parte pro próximo.

    for (i=0;i<tamanho;i++){
        for (j=0;j<tamanho;j++){

            do{
                igual = 0;
                srand((unsigned)time(NULL));
                teste = rand()%(tamanho*tamanho+5);
                for (w=0;w<=i;w++){
                    if (w==i){                        
                        for (k=0;k<j;k++){  
                            if (teste == matriz[w][k]){
                                igual++;
                            }
                        }
                    }
                    else{
                        for (k=0;k<=tamanho;k++){
                            if (teste == matriz[w][k]){
                                igual++;
                            }
                        }
                    }   
                }
                if (igual == 0){
                    matriz[i][j]=teste;
                    printf("|");
                    break;
                }
            } while (1);
        }
    }

    printf(")");
    printf("\n\n");

    // Estrutura para imprimir a matriz na tela.
    for (i=0;i<tamanho;i++){
        for (j=0;j<tamanho;j++){
            printf("\t%i",matriz[i][j]);
        }
    printf("\n\n\n");
    }

  return 0;
}