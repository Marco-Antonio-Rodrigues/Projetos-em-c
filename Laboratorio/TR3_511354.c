#include <stdio.h>
#include <stdlib.h>

//MODELO DE EXEMPLO

int main(){
   
   	//VariÃ¡veis que podem ser usadas
   	unsigned int x[200];
   	int y;
   	int z;
   	int k;
   	int w;
   	int j;
   	int i;
   	
   	//#########################
   	for(z=0;z<=200;z++){//setando valores para garantir que sao zeros
      x[z]=0;
    }
    z = y = 0;
		printf("Digite -1 para encerrar\nDigite qualquer numero de 0 e 5000:\n");
    while (y != -1){// laco onde adiciona os numeros
      scanf("%i",&y);
			if(y != -1){
        x[y/32] = x[y/32] | (1<<(y%32));
			}
    }
		printf("Os numeros digitados em ordem crescente foram:\n");
    for(z=0;z<=200;z++){		// laco para imprimir todos os numeros digitados
      for(y=0;y<32;y++){
        if((x[z]&(1<<y)) != 0){
          printf("\n%i",((z*32)+y));
        }
      }
    }
   	//#########################
   
	return 0;  
}