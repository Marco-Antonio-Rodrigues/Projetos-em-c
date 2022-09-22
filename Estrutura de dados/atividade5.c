#include <stdio.h>
#include <stdlib.h>

typedef struct ImoveisDaRua{
  char *complemento;
  char imovelComercial;
  struct ImoveisDaRua *prox;
  int numero;
}IDR;

int main(){
  IDR *mercantil1= malloc(sizeof(IDR));
  IDR *apartamento17 = malloc(sizeof(IDR));
  IDR *casa342 = malloc(sizeof(IDR));

  casa342->complemento = "Casa, 284m2.";
  casa342->imovelComercial = 'N';
  casa342->numero = 342; 

  apartamento17->complemento = "Predio, 4 Andares, 182 m2.";
  apartamento17->imovelComercial = 'N';
  apartamento17->numero = 17;

  mercantil1->complemento = "Casa Comercial, 521 m2";
  mercantil1->imovelComercial = 'S';
  mercantil1->numero = 1;

  casa342->prox = apartamento17;
  apartamento17->prox = mercantil1;
  mercantil1 = NULL;
  return 0;
  //Casa->Apartamento->Mercantil->Fim da rua
}
