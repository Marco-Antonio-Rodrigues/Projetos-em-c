#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int elevado(int a, int b){
  if (b == 0){
    return 1;
  }else{
    b = b - 1;
    a = a * elevado(a, b);
    return a;
  }
}

int PrintHeap(HEAP *heap){
  // printf("tamanho:%i numero de elementos: %i\n", heap->N, heap->P);
  // int c = 1;
  // for (int i = 0; i < 5; i++){
  //   printf("nivel %i:", i+1);
  //   for (int j = 1; j <= elevado(2, i); j++){
  //     if (c <= heap->P){
  //       printf("\t%i", heap->elems[c]);
  //       c++;
  //     }
  //   }
  //   printf("\n");
  // }
  printf("vetor:");
  for (int i = 1; i <= heap->P; i++){
    if(heap->elems[i] != 0)
      printf("v[%i]= %i  ", i,heap->elems[i]);
  }
  printf("\n\n\n");
}

int main(){
  int vetor[2]= {0,2};
  HEAP* novoheap = HEAP_build(vetor,1);
  PrintHeap(novoheap);
  // HEAP_remove(novoheap);
  // HEAP_add(novoheap,3);
  insertionSort(novoheap);
  PrintHeap(novoheap);


  return 0;
}