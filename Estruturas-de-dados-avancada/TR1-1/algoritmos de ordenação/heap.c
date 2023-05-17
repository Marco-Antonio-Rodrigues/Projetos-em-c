#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void moveUp(int *array,int pos){
	int aux = pos/2;
	if(aux>=1){
		if(array[pos] > array[aux]){
			int swap = array[pos];
			array[pos] = array[aux];
			array[aux] = swap;
			moveUp(array,aux);
		}
	}
}

void moveDown(int *array,int pos,int n){
	int aux = 2 * pos;
	if(aux<= n){
		if(aux<n){
			if(array[aux+1] > array[aux]){
				aux++;
			}
		}
		if(array[pos] < array[aux]){
			int swap = array[pos];
			array[pos] = array[aux];
			array[aux] = swap;
			moveDown(array,aux,n);
		}
	}
}

void HEAP_arranjar(int *array){
		for(int i=array[0]/2;i>=1;i--){
		moveDown(array,i,array[0]);
	}
}

HEAP* HEAP_build(int* t,int n){
	HEAP *new_HEAP = malloc(sizeof(HEAP));
	new_HEAP->N = n;
	new_HEAP->P = n;
	new_HEAP->elems = t;
	HEAP_arranjar(t);
	return new_HEAP;
}

void HEAP_add(HEAP* heap, int newelem){
  if(heap->P < heap->N){//verifica se o heap nao esta cheio
		heap->elems[heap->P+1] = newelem;	// insere no final do heap/vetor
		moveUp(heap->elems,(heap->P)+1);
		heap->P++;
	}else{
		printf("\nERRO! HEAP CHEIO.");
	}
}

int HEAP_remove(HEAP* heap){
  int lixo;
	if(heap->P > 0){
		lixo = heap->elems[1];
		heap->elems[1] = heap->elems[heap->P];
		heap->elems[heap->P] = 0;
		heap->P--;
		moveDown(heap->elems,1,heap->P);
		return lixo;
	}else{
		printf("\nERRO! HEAP VAZIO");
		return lixo;
	}
}

void heapSort(HEAP* heap){
	int aux = heap->P;
	while (aux > 1){
		int swap = heap->elems[1];
		heap->elems[1] = heap->elems[aux];
		heap->elems[aux] = swap;
		aux--;
		moveDown(heap->elems,1,aux);
	}
}

void insertionSort(HEAP* heap){
	int aux = heap->P;
	if(aux > 1){
		for(int i = 2; i <= heap->P;i++){ //for que adiciona
			for(int j = i;j>1;j--){ //for que ordena
				if(heap->elems[j-1] > heap->elems[j]){
					int swap = heap->elems[j-1];
					heap->elems[j-1] = heap->elems[j];
					heap->elems[j] = swap;
				}
			}
		}
	}
}

HEAP *readfile(FILE *read){
  int aux;
	fscanf(read,"%i",&aux);
  int* array = malloc(sizeof(int)*(aux+1));
	array[0] = aux;
	// printf("\nentrou %i",array[1]);
  for(aux = 1 ;aux <= array[0];aux++){  //aux e so pra dizer o numero de vezes de repet faz o preencimento da matriz
    fscanf(read,"%i ",&array[aux]);
  }
	HEAP* newheap = HEAP_build(array,array[0]);
  return newheap;
}

