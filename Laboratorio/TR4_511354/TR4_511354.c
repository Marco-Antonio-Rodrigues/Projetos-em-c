#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

int FunctionComparador(void* x, void* y){
	if(x > y){
		return -1;
	}else if(x == y) {
		return 0;
	}else if(x < y){
		return 1;
	}
	else{
		return 3550;//erro
	}
}

VETORORD* VETORD_create(int n, COMP* compara){//vetor ordenador na ordem crescente
	VETORORD *new_vetorord = malloc(sizeof(VETORORD));
	new_vetorord->N = n;
	new_vetorord->P = 0;
	new_vetorord->elems = malloc(sizeof(int)*n); //cria um vetor de ponteiros de tamanho n(trocar)
	new_vetorord->comparador = FunctionComparador;
	for(int i=0;i<new_vetorord->N;i++){
		new_vetorord->elems[i]=0;
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
					int aux = vetor->elems[i];
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
void PrintVetor(VETORORD *vetor){
	printf("Tamanho do vetor: %i, Quantidade de elementos: %i\n",vetor->N,vetor->P);
	for(int i=0;i<vetor->P;i++){
		printf("vetor[%i] == %i\n",i,vetor->elems[i]);
	}
}
int main(){
	COMP *comparador = FunctionComparador;
	VETORORD *novovetor = VETORD_create(4,comparador);
	// printf("posicao: vetor[%i] valor:%i\n",1,novovetor->elems[1]);
	// printf("tamanho do vetor: %i",novovetor->N);
	VETORD_add(novovetor,3);
	VETORD_add(novovetor,2);
	VETORD_add(novovetor,2);
	PrintVetor(novovetor);
}