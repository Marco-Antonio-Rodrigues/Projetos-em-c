#include "ordvetor.h"
#include <stdio.h>
#include <stdlib.h>

VETORORD* VETORD_create(int n, COMP* compara){//vetor ordenador na ordem crescente
	VETORORD *new_vetorord = malloc(sizeof(VETORORD));
	new_vetorord->N = n;
	new_vetorord->P = 0;
	new_vetorord->elems = malloc(sizeof(new_vetorord->elems)*n);
	new_vetorord->comparador = compara;
	for(int i=0;i<new_vetorord->N;i++){// garantindo que aponta para NULL
		new_vetorord->elems[i]=NULL;
	}
	return new_vetorord;
}

void VETORD_add(VETORORD* vetor, void* newelem){
	if(vetor->P < vetor->N){//verifica se o vetor nao esta cheio
		if (vetor->P == 0){ //caso o vetor ainda esteja vazio
			vetor->elems[0] = newelem;
			vetor->P++;
		}else{ // adiciona ordenado
			vetor->elems[vetor->P] = newelem;		
			for (int i = vetor->P; i >= 1; i--){
				if((vetor->comparador(vetor->elems[i-1],vetor->elems[i]))==1){//aqui
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

void* VETORD_remove(VETORORD* vetor){//apaga o primeiro elemento e empurra o vetor
	void *lixo = vetor->elems[0];
	for (int i = 0; i < vetor->P-1; i++){
		vetor->elems[i]=vetor->elems[i+1];
	}
	vetor->elems[vetor->P-1] = NULL;
	vetor->P--;
	return lixo;
}