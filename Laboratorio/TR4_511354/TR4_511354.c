#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordvetor.h"

int FunctionComparador(void* x, void* y){//ok
	if(x > y){
		return -1;
	}else if(x == y) {
		return 0;
	}else{
		return 1;
	}
}

VETORORD* VETORD_create(int n, COMP* compara){//vetor ordenador na ordem crescente
	VETORORD *new_vetorord = malloc(sizeof(VETORORD));
	new_vetorord->N = n;
	new_vetorord->P = 0;
	new_vetorord->elems = malloc(sizeof(new_vetorord->elems)*n);
	new_vetorord->comparador = FunctionComparador;
	for(int i=0;i<new_vetorord->N;i++){
		new_vetorord->elems[i]=NULL;
	}
	return new_vetorord;
}

void VETORD_add(VETORORD* vetor, void* newelem){
	if(vetor->P < vetor->N){//verifica se o vetor nao esta cheio
		if (vetor->P == 0){ //caso o vetor ainda esteja vazio
			vetor->elems[0] = newelem;
			vetor->P++;
		}else{
			vetor->elems[vetor->P] = newelem;		
			for (int i = vetor->P; i >= 1; i--){
				if(FunctionComparador(vetor->elems[i-1],vetor->elems[i])==-1){
					void *aux = vetor->elems[i];
					vetor->elems[i] = vetor->elems[i-1];
					vetor->elems[i-1] = aux;
				}else{
					break;
				}	
		}
		vetor->P++;
	}
}
}

void* VETORD_remove(VETORORD* vetor){ //ok
	void *lixo = vetor->elems[0];
	for (int i = 0; i < vetor->P-1; i++){
		vetor->elems[i]=vetor->elems[i+1];
	}
	vetor->elems[vetor->P-1] = NULL;
	vetor->P--;
	return lixo;
}

void PrintVetor(VETORORD *vetor){ //pode apagar
	printf("Tamanho do vetor: %i, Quantidade de elementos: %i\n",vetor->N,vetor->P);
	if(vetor->P != 0){
		for(int i=0;i<vetor->P;i++){
			printf("vetor[%i] == %f",i,vetor->elems[i]);
			printf("\n");
		}
	}
}

int main(){//problema ao usar float

}