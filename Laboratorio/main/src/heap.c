#include "heap.h"

int FunctionComparador(void* x, void* y){
	if(*(int*)x <*(int*)y){
		return 1;
	}else if(*(int*)x == *(int*)y) {
		return 0;
	}else{
		return -1;
	}
}

HEAP* HEAP_create(int n, COMP* compara){
  HEAP *new_HEAP = malloc(sizeof(HEAP));
	new_HEAP->N = n;
	new_HEAP->P = 0;
	new_HEAP->elems = malloc(sizeof(new_HEAP->elems)*n);
	new_HEAP->comparador = compara;
	for(int i=0;i<new_HEAP->N;i++){// garantindo que aponta para NULL
		new_HEAP->elems[i]=NULL;
	}
	return new_HEAP;
}

void HEAP_add(HEAP* heap, void* newelem){
  if(heap->P < heap->N){//verifica se o heap nao esta cheio
		heap->elems[heap->P] = newelem;	// insera no final do heap/vetor
		int pai;
		int pos = (int)heap->P;
		while (pos > 0) {
			pai = (pos-1)/2;
			if (*(int*)heap->elems[pai] > *(int*)heap->elems[pos]){
				void* aux = heap->elems[pos];
				heap->elems[pos] = heap->elems[pai];
				heap->elems[pai] = aux;
			}else{
				break;
			}
			pos = pai;
		}
			heap->P++;
	}else{
		printf("ERRO! HEAP CHEIO.");
	}
}

void* HEAP_remove(HEAP* heap){
  void *lixo = NULL;
	if(heap->P > 0){
		lixo = heap->elems[0];
		heap->elems[0] = heap->elems[heap->P-1];
		heap->elems[heap->P-1] = NULL;
		heap->P--;
		int pai = 0,filho_esq, filho_dir, filho;
		while ((2*pai+1) < heap->P){
			filho_esq=2*pai+1;
 			filho_dir=2*pai+2;
			if (filho_dir >= heap->P){
				filho_dir=filho_esq;
			}
			if (*(int*)heap->elems[filho_esq] < *(int*)heap->elems[filho_dir]){
   			filho = filho_esq; 
			}else{
				filho = filho_dir;
			}
			 if (heap->elems[pai] > heap->elems[filho]){
					void *aux = heap->elems[pai];
					heap->elems[pai] = heap->elems[filho];
					heap->elems[filho] = aux;
			 } else{
  				break;
			 }
			 pai = filho;
		}  
		return lixo;
	}else{
		printf("ERRO! HEAP VAZIO");
		return lixo;
	}
}

int elevado(int a,int b){
    if(b == 0){
        return 1;
    }else{
        b = b - 1;
        a = a * elevado(a,b);
				return a;
    }
}

void PrintHeap(HEAP *heap){
	printf("tamanho:%i numero de elementos: %i\n",heap->N,heap->P);
	int c = 0;
  for (int i=0;i<10;i++){
		printf("nivel %i:",i);
		for (int j = 1; j <= elevado(2,i); j++){
			if(c<heap->P){
			printf("\t%i",*(int*)heap->elems[c]);
			c++;
			}
		}
		printf("\n");
	}
	printf("vetor:");
	for (int i = 0; i < heap->P; i++){
		printf("v[%i]=%i  ",i,*(int*)heap->elems[i]);
	}
	
		printf("\n\n\n");
}

