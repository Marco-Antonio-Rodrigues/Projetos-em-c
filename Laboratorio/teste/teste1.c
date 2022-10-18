#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  float numero = 1.2; //endereco de numero recebe o valor 1 
  float *pont_num = &numero; // variavel pont_num = endereco de numero
  void *pont_void = &numero; //varaivel pont_void = endereco de  pont_num
  printf("Informacoes de numero: %f %i",numero,&numero);
  printf("\nInformacoes de numero: %f %i",*(float*)pont_num,&pont_num);
  printf("\nInformacoes de numero: %f %i",*(float*)pont_void,&pont_void);


	return 0;
}