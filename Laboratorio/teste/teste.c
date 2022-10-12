#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(void *a, void *b){
  int size = sizeof(a);
  void *aux = malloc(size);
  memcpy(aux,a,size);
  memcpy(a,b,size);
  memcpy(b,aux,size);
  aux = NULL;
  free(aux);
}

int main(){
	char vetor1[] = "bb";
	char vetor2[] = "aa";
	char vetor3[] = "c";

  void *pont1 = vetor1;
  void *pont2 = vetor2;

  printf("aqui: %s\n",vetor1);
  printf("aqui: %s\n",vetor2);
  trocar(pont1,pont2);
  printf("aqui: %s\n",vetor1);
  printf("aqui: %s\n",vetor2);
}