#include "TR67_511354.h"
#include <stdio.h>
#include <stdlib.h>

//LOGICA
// usar operadores bit a bit
// usar vetores

Set *readSet(FILE *read){//ok
  int aux;
  Set *new_set = malloc(sizeof(Set));
  fscanf(read,"%d",&new_set->number_elems);
  fscanf(read,"%d",&new_set->value_max);
  fscanf(read,"%f",&new_set->density);
  new_set->set = (int*)malloc(sizeof(int)*(new_set->number_elems/32));
  for(aux=0;aux<=new_set->number_elems/32;aux++){//setando valores para garantir que sao zeros
    new_set->set[aux]=0;
  }
  for(int i = 0;i<new_set->number_elems;i++){
    fscanf(read,"%d",&aux);
    new_set->set[aux/32] = new_set->set[aux/32] | (1<<(aux%32));
  }
  return new_set;
}

Set *emptySet(){ //cria um conjunto vazio
  Set *new_set = malloc(sizeof(Set));
  return new_set;
}


int main(){
  FILE *file = fopen("teste.txt","r");
  Set *conjunto = readSet(file);
  printf("%i\n",conjunto->number_elems);
  printf("%i\n",conjunto->value_max);
  printf("%f\n",conjunto->density);
  printf("%i\n",conjunto->set[0]);
  printf("%i\n",conjunto->set[1]);

  for(int z=0;z<=conjunto->number_elems/32+1;z++){		// laco para imprimir todos os numeros digitados
    for(int y=0;y<32;y++){
      if((conjunto->set[z]&(1<<y)) != 0){
        printf("\n%i",((z*32)+y));
      }
    }
  }
  return 0;
}