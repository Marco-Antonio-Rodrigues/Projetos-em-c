// Por: Marco Antonio Rodrigues Gomes de Souza
// Descrição: Cria uma array sem repetir valores e de qualquer ordem.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeSet(FILE *write,int *read){
    fprintf(write,"%i\n",read[0]);
    for(int i = 1;i<=(read[0]);i++){
        fprintf(write,"%i\n",read[i]);
    }
}
int main(int argc,char** argv){
    FILE* file = fopen(argv[1], "w");

    srand(time(NULL));

    int tamanho,j,k,igual = 0,newelement; //tamanho do array

    printf("Digite o tamanho do array: ");
    scanf("%i",&tamanho);

    int *array = malloc(sizeof(int)* tamanho);
    int intervalo = tamanho+1000;

    // Estrutura de criação da array, a cada número gerado o algoritmo faz a validação 
    // para validar se não há valores iguais, se tiver ele gera outro e repete o processo, 
    // se não ele adiciona e parte pro próximo.
    array[0] = tamanho;
    for (j=1;j<=tamanho;j++){
        do{
            igual = 0;
            newelement = 1 + rand()%intervalo;                   
            for (k=1;k<j;k++){  
                if (newelement == array[k]){
                    igual++;
                    break; //somente do for
                }
            }
            if (igual == 0){
                array[j]=newelement;
                printf("\nadd %i",j);
                break;
            }
        } while (1);
    }
    writeSet(file,array);
    fclose(file);
  return 0;
}