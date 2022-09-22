#include <stdio.h> 
#include <stdlib.h>

int main(){
  int x = 1;
  int *p = &x;
  *p = x;
  int a = (*p);
  int *k = &a;
  x = a;
  p = k;
  a = x;
  printf("\n%i \n%p \n%i",x,p,a);
  return 0;
}
//Continua o mesmo
