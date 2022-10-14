#include <stdlib.h>
#include <stdio.h>

typedef struct heap {
 int max; /* tamanho maximo do heap */
 int pos; /* proxima posicao disponivel no vetor */
 int* prioridade; /* vetor das prioridades */
}Heap; /* ignorando os dados! */

Heap* heap_cria(int max) {
 Heap* heap=(Heap*)malloc(sizeof(struct heap));
 heap->max=max;
 heap->pos=0;
 heap->prioridade=(int *)malloc(max*sizeof(int));
 return heap;
}

void troca(int a, int b, int* v) {
int f = v[a];
v[a] = v[b];
v[b] = f;
}

void corrige_acima(Heap* heap, int pos) {
 int pai;
 while (pos > 0) {
  pai = (pos-1)/2;
  if (heap->prioridade[pai] < heap->prioridade[pos]){
    troca(pos,pai,heap->prioridade);
  }else{
    break;
  }
  pos=pai;
 }
}

void heap_insere(Heap* heap, int prioridade) {
 if ( heap->pos < heap->max ) {
  heap->prioridade[heap->pos]=prioridade;
  // corrige_acima(heap,heap->pos);
  int pai;
  int pos = (int)heap->pos;
 while (pos > 0) {
  pai = (pos-1)/2;
  if (heap->prioridade[pai] > heap->prioridade[pos]){
    // troca(pos,pai,heap->prioridade);
    int aux = heap->prioridade[pos];
    heap->prioridade[pos] = heap->prioridade[pai];
    heap->prioridade[pai] = aux;
    //.
  }else{
    break;
  }
  pos=pai;
 }
 //.
 heap->pos++;
 }
 else
 printf("Heap CHEIO!\n");
}


static void corrige_abaixo(int *prios, int atual, int tam){
 int pai = atual;
 int filho_esq, filho_dir, filho;
 while (2*pai+1 < tam){
  filho_esq=2*pai+1;
  filho_dir=2*pai+2;
  if (filho_dir >= tam) filho_dir=filho_esq;
    if (prios[filho_esq] > prios[filho_dir])
      filho = filho_esq;
    else
      filho = filho_dir;
  if (prios[pai] < prios[filho]){
    troca(pai,filho,prios);
  }else{
    break;
  }
  pai = filho;
 }
}

int heap_remove(Heap* heap) {
 if (heap->pos > 0) {
 int topo = heap->prioridade[0];
 heap->prioridade[0] = heap->prioridade[heap->pos-1];
 heap->pos--;
 corrige_abaixo(heap->prioridade, 0, heap->pos);
 return topo;
 }
 else {
 printf("Heap VAZIO!");
 return -1;
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

void PrintHeap(Heap *heap){
	printf("tamanho:%i numero de elementos: %i\n",heap->max,heap->pos);
	int c = 0;
  for (int i=0;i<10;i++){
		printf("nivel %i:",i);
		for (int j = 1; j <= elevado(2,i); j++){
			if(c<heap->pos){
			printf("\t%i",heap->prioridade[c]);
			c++;
			}
		}
		printf("\n");
	}
	printf("vetor:");
	for (int i = 0; i < heap->pos; i++){
		printf("v[%i]=%i  ",i,heap->prioridade[i]);
	}
	
		printf("\n\n\n");
}
int main(){
  Heap *newheap = heap_cria(20);
  heap_insere(newheap,9);
  heap_insere(newheap,7);
  heap_insere(newheap,2);
  heap_insere(newheap,6);
  heap_insere(newheap,4);
  heap_insere(newheap,1);
  heap_insere(newheap,9);
  heap_insere(newheap,7);
  heap_insere(newheap,2);
  heap_insere(newheap,6);
  heap_insere(newheap,4);
  heap_insere(newheap,1);
 

  PrintHeap(newheap);
  // printf("\n%i",newheap->prioridade[0]);
  // heap_remove(newheap);
  // printf("\n%i",newheap->prioridade[0]);
  return 0;
}


