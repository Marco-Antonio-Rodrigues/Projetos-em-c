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

void writeSet(FILE *write, Set *read){
  fprintf(write,"%i",read->number_elems);
  fprintf(write,"\n%i",read->value_max);
  fprintf(write,"\n%f",read->density);
  for(int z=0;z<=read->number_elems/32+1;z++){		// laco para imprimir todos os numeros digitados
    for(int y=0;y<32;y++){
      if((read->set[z]&(1<<y)) != 0){
        fprintf(write,"\n%i",((z*32)+y));
      }
    }
  }
}

void unionSet(Set *write,Set *read1,Set *read2){
  int limit;
  if(read1->value_max >= read2->value_max){
    write->value_max = read1->value_max;
    limit = read2->value_max;
  }else{
    write->value_max = read2->value_max;
    limit = read1->value_max;
  }
  //ate aqui ok -- pegamos o valor maximo
  int i;
  for(i = 0;i<=limit/32;i++){
    write->set[i] = read1->set[i] | read2->set[i];
  }
  int some;
  for(int c = 0;c<32;c++){
    if((write->set[i*32] & (1<<c))== 1){
      some++;
    }
  }
  write->number_elems = ((i*32)-1)+some;
}

int main(){
  FILE *read = fopen("teste.txt","r");
  FILE *write = fopen("escreva.txt","w");
  Set *conjunto1 = readSet(read);
  Set *conjunto2 = readSet(read);
  Set *conjunto_uniao = emptySet();
  writeSet(write,conjunto_uniao);

  // for(int z=0;z<=conjunto->number_elems/32+1;z++){		// laco para imprimir todos os numeros digitados
  //   for(int y=0;y<32;y++){
  //     if((conjunto->set[z]&(1<<y)) != 0){
  //       printf("\n%i",((z*32)+y));
  //     }
  //   }
  // }
  return 0;
}