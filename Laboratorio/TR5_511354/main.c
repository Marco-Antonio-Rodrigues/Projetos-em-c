#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int FunctionComparador(void *x, void *y)
{
  int ptx = *((int *)x);
  int pty = *((int *)y);
  if (ptx < pty){
    return 1;
  }else if (ptx > pty){
    return -1;
  }else{
    return 0;
  }
}

int elevado(int a, int b)
{
  if (b == 0)
  {
    return 1;
  }
  else
  {
    b = b - 1;
    a = a * elevado(a, b);
    return a;
  }
}

void PrintHeap(HEAP *heap)
{
  printf("tamanho:%i numero de elementos: %i\n", heap->N, heap->P);
  int c = 0;
  for (int i = 0; i < 10; i++)
  {
    printf("nivel %i:", i);
    for (int j = 1; j <= elevado(2, i); j++)
    {
      if (c < heap->P)
      {
        printf("\t%i", *(int *)heap->elems[c]);
        c++;
      }
    }
    printf("\n");
  }
  printf("vetor:");
  for (int i = 0; i < heap->P; i++)
  {
    printf("v[%i]=%i  ", i, *(int *)heap->elems[i]);
  }

  printf("\n\n\n");
}

int main(){
  HEAP *novoheap = HEAP_create(50, FunctionComparador);
  int n1 = 9;
  int n2 = 7;
  int n3 = 2;
  int n4 = 6;
  int n5 = 4;
  int n6 = 1;
  int *pont;
  pont = &n1;
  HEAP_add(novoheap, pont);
  PrintHeap(novoheap);

  HEAP_remove(novoheap);
  PrintHeap(novoheap);

  pont = &n2;
  HEAP_add(novoheap, pont);
  PrintHeap(novoheap);

  pont = &n3;
  HEAP_add(novoheap, pont); // quando comentei aumentou dois
  PrintHeap(novoheap);

  pont = &n4;
  HEAP_add(novoheap, pont); // n serve
  PrintHeap(novoheap);

  pont = &n5;
  HEAP_add(novoheap, pont); // n serve
  PrintHeap(novoheap);

  pont = &n6;
  HEAP_add(novoheap, pont);
  PrintHeap(novoheap);

  pont = &n1;
  HEAP_add(novoheap, pont);
  PrintHeap(novoheap);

  pont = &n2;
  HEAP_add(novoheap, pont);
  PrintHeap(novoheap);

  pont = &n4;
  HEAP_add(novoheap, pont); // n serve
  PrintHeap(novoheap);
  //
  HEAP_remove(novoheap);
  PrintHeap(novoheap);

  return 0;
}