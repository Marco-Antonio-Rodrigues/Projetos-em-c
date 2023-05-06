// (x)subir 
// (x)descer 
// (x)inserir
// (x)remover
// (x)construir
// ()Implementar o HeapSort.
// ()Implementar o InsertionSort
//nao pode add elements iguais
#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

//Uma Heap estatico. Os elementos do vetor estao colocadoo no vetor
//de acordo com a ordem indicada por comparador.
typedef struct heap{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	int* elems;//o vetor de elementos
}HEAP;

int moveUp(HEAP* heap,int pos);

int moveDown(HEAP* heap,int pos,int n);

/**
Cria um heap vazio de tamanho n e com funcao de comparacao compara

@param n: o tamanho do heap
@param compara: a funcao de comparacao

@return um ponteiro para uma estrutura HEAP, observe que este ponteiro ja
deve apontar para a estrutura, ou seja, a alocacao de memoria deve ser feita nele.
*/
HEAP* HEAP_build(int* t,int n);

/**
Adiciona o elemento newelem ao Heap, na posicao correta se for possÃ­vel
ainda incluir o elemento (se existe espaco no vetor elems).

@param heap: o heap a ter o elemento incluÃ­do
@param newelem: o elemento a ser adicionado
*/
void HEAP_add(HEAP* heap, int newelem);

/**
Remove o menor elemento do heap, de acordo com a funcao compara

@param heap: o heap a ter seu elemento removido

@return um ponteiro para o elemento que foi removido do heap.
*/
int HEAP_remove(HEAP* heap);

void heapSort(HEAP* heap);

void insertionSort(HEAP* heap);



#endif

