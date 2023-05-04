#include <stdio.h>
#include <stdlib.h>

int main(){
   
   	unsigned int x[200];
   	int y, z;
   	
		//setando valores para garantir que sao zeros
   	for(z=0;z<=200;z++){
      x[z]=0;
    }
    z = y = 0;

		printf("Digite -1 para encerrar\nDigite qualquer numero de 0 a 5000:\n");
		// laco onde o usuario adiciona os numeros
    while (y != -1){
      scanf("%i",&y);
			if(y != -1){
        x[y/32] = x[y/32] | (1<<(y%32));
			}
    }
		printf("Os numeros digitados em ordem crescente foram:\n");
		// laco para imprimir todos os numeros digitados em ordem crescente
    for(z=0;z<=200;z++){
      for(y=0;y<32;y++){
        if((x[z]&(1<<y)) != 0){
          printf("\n%i",((z*32)+y));
        }
      }
    }
   
	return 0;  
}