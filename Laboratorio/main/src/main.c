#include "heap.c"

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
	HEAP_remove(novoheap);

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
	HEAP_remove(novoheap);

  pont = &n5;
  HEAP_add(novoheap,pont);// n serve

	pont = &n6;
  HEAP_add(novoheap,pont);
	HEAP_remove(novoheap);

	PrintHeap(novoheap);
  return 0;
}