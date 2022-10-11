#include "teste.h"

int FunctionComparador(void* x, void* y){
	if(x > y){
		return -1;
	}else if(x == y) {
		return 0;
	}else{
		return 1;
	}
}

VETORORD* VETORD_create(int n, COMP* compara){
	VETORORD *new_vetorord = malloc(sizeof(VETORORD));
	new_vetorord->N = n;
	new_vetorord->P = 0;
	new_vetorord->elems = malloc(sizeof(int)*n); //cria um vetor de ponteiros de tamanho n(trocar)
	new_vetorord->comparador = FunctionComparador;
	return new_vetorord;
}


