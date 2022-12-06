#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//FunÃ§Ã£o de comparaÃ§Ã£o
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx < pty){ 
		return 1;
	}else{
		if(ptx > pty){
			return -1;
		}else
			return 0;
	}
}

//Print para a estrutura
void print(void** vet, int P){
	int i;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < P; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = VETORD_create(10, myCOMP);
   	
   	int* x;
   	int i;
   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < 10; i++){
		x = malloc(sizeof(int));
		*x = i*10;
		VETORD_add(vet, x);
	}
	
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!");
  	VETORD_remove(vet);
  	
	print(vet->elems, vet->P);
   
	return 0;  
}