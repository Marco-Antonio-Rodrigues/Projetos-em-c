#include <stdio.h>

int main(){
   
   	//VariÃ¡veis que podem ser usadas
   	int x;
   	int y;
   	int z;
   	int k;
   	int w;
   	int j;
   	int i;
   	
   	//#########################
    x = y = 0;
		printf("Digite -1 para encerrar");
		printf("\nDigite qualquer numero entre 0 e 31:\n");
		// laco onde adiciona os numeros
    while (y != -1){
      scanf("%i",&y);
			if(y != -1){
      	x = x|(1<<y);
			}
    }
		printf("Os numeros digitados em ordem crescente foram:\n");
		// laco para imprimir todos os numeros digitados
    for(y=0;y<=31;y++){
      if((x&(1<<y)) != 0){
        printf("\n%i",y);
      }
    }
   	//#########################
	return 0;  
}