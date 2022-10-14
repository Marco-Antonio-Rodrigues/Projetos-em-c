#include "heap.h"
#include <math.h>

int FunctionComparador(void* x, void* y){
	if(*(int*)x <*(int*)y){
		return 1;
	}else if(*(int*)x == *(int*)y) {
		return 0;
	}else{
		return -1;
	}
}

HEAP* HEAP_create(int n, COMP* compara){//ok
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

// Insira o elemento no final do heap e faça-o “subir” até a
// posição correta
void HEAP_add(HEAP* heap, void* newelem){
  if(heap->P < heap->N){//verifica se o heap nao esta cheio
		heap->elems[heap->P] = newelem;	// ate aqui ta certo	
		//  corrige_acima(heap,heap->pos);
		int pai;
		int pos = (int)heap->P;
		while (pos > 0) {
			pai = (pos-1)/2;
			if (*(int*)heap->elems[pai] > *(int*)heap->elems[pos]){
				// troca(pos,pai,heap->prioridade);
				printf("\nentrou: %i  %i",*(int*)heap->elems[pos],*(int*)heap->elems[pai]);
				void* aux = heap->elems[pos];
				heap->elems[pos] = heap->elems[pai];
				heap->elems[pai] = aux;
				//.
			}else{
				break;
			}
			pos = pai;//parte errada
		}
		//.
			heap->P++;
	}else{
		printf("ERRO! HEAP CHEIO.");
	}
}


// Retira-se sempre a raiz
// Coloque na raiz o último elemento do heap e faça-o
// “descer” até a posição correta
void* HEAP_remove(HEAP* heap){// precisa implementar um mecanismo de reordem
  void *lixo = NULL;
	if(heap->P > 0){
		lixo = heap->elems[0];
		heap->elems[0] = heap->elems[heap->P-1];
		heap->elems[heap->P-1] = NULL;
		heap->P--;//ate aqui ta certo
		int pai = 0,filho_esq, filho_dir, filho;
		while ((2*pai+1) < heap->P){
			filho_esq=2*pai+1;
 			filho_dir=2*pai+2;
			if (filho_dir >= heap->P){
				filho_dir=filho_esq;
			}//ok ate aqui
			if (*(int*)heap->elems[filho_esq] < *(int*)heap->elems[filho_dir]){//alt
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

//apagar
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

int main(){
  HEAP *novoheap = HEAP_create(50,FunctionComparador);
  int n1 = 9;
  int n2 = 7;
  int n3 = 2;
	int n4 = 6;
  int n5 = 4;
  int n6 = 1;
  void *pont;
	pont = &n1;
  HEAP_add(novoheap,pont);

  pont = &n2;
  HEAP_add(novoheap,pont);

  pont = &n3;
  HEAP_add(novoheap,pont);//quando comentei aumentou dois

	pont = &n4;
  HEAP_add(novoheap,pont);//n serve

  pont = &n5;
  HEAP_add(novoheap,pont);// n serve

	pont = &n6;
  HEAP_add(novoheap,pont);

	pont = &n1;
  HEAP_add(novoheap,pont);

  pont = &n2;
  HEAP_add(novoheap,pont);

  pont = &n3;
  HEAP_add(novoheap,pont);//quando comentei aumentou dois

	pont = &n4;
  HEAP_add(novoheap,pont);//n serve

  pont = &n5;
  HEAP_add(novoheap,pont);// n serve

	pont = &n6;
  HEAP_add(novoheap,pont);

	PrintHeap(novoheap);
  return 0;
}