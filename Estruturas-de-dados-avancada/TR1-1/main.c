#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  printf("\ntamanho:%i numero de elementos: %i\n", heap->N, heap->P);
  int c = 1;
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
  printf("\nvetor:");
  for (int i = 1; i <= heap->P; i++){
    if(heap->elems[i] != 0)
      printf("v[%i]= %i  ", i,heap->elems[i]);
  }
}

int main(int argc,char** argv){
  FILE* file = fopen(argv[1], "r");
  HEAP* novoheap = readfile(file);
  
  double time_spent = 0.0;
  clock_t begin = clock();
  heapSort(novoheap);
  
  fclose(file);
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\nheapSort:%f seconds", time_spent);
  return 0;
}