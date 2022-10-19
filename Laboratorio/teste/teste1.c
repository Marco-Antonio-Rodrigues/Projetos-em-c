#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(int *a,int *b){
  int aux = *(int*)a;
  *a = *b;
  *b = aux;
  printf("a:%i  b:%i",*a,*b);
}

int FunctionComparador(void* x, void* y){
	if(*(int*)x <*(int*)y){
		return 1;
	}else if(*(int*)x == *(int*)y) {
		return 0;
	}else{
		return -1;
	}
}

int main(){
  int num1 = 1;
  int num2 = 2;

  void *pont1 = &num1;
  void *pont2 = &num2;

  char string1[] = "aa"; 
  char string2[] = "aa"; 

  pont1 = string1;
  pont2 = string2;
  printf("aqui: %i",FunctionComparador(pont1,pont2));
  // printf("\nnum1:%i  num2:%i",num1,num2);


	return 0;
}