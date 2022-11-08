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
  new_set->set = (int*)malloc(sizeof(int)*(new_set->value_max/32));
  for(aux=0;aux<=new_set->value_max/32;aux++){//setando valores para garantir que sao zeros
    new_set->set[aux]=0;
  }
  for(int i = 0;i<new_set->value_max;i++){
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
  for(int z=0;z<=read->value_max/32+1;z++){		// laco para imprimir todos os numeros digitados
    for(int y=0;y<32;y++){
      if((read->set[z]&(1<<y)) != 0){
        fprintf(write,"\n%i",((z*32)+y));
      }
    }
  }
}

void unionSet(Set *write,Set *read1,Set *read2){
  int aux;
  write->number_elems = 0;
  if(read1->value_max >= read2->value_max){
    write->value_max = read1->value_max;
    write->set = malloc(sizeof(int)*read1->value_max/32);
    for(aux = 0;aux<=read1->value_max/32; aux++){
      write->set[aux] = read1->set[aux];
    }
    for(aux = 0;aux<=read2->value_max/32; aux++){
      write->set[aux] = write->set[aux] | read2->set[aux];
    }
  }else{
    write->value_max = read2->value_max;
    write->set = malloc(sizeof(int)*read2->value_max/32);
    for(aux = 0;aux<=read2->value_max/32; aux++){
      write->set[aux] = read2->set[aux];
    }
    for(aux = 0;aux<=read1->value_max/32; aux++){
      write->set[aux] = write->set[aux] | read1->set[aux];
    }
  }
  //ate aqui ok -- pegamos o valor maximo -- setamos o tamanho do array -- preeenchemos o array -- fizemos a uniao
  for(aux = 0;aux<=write->value_max+1;aux++){
    if((write->set[aux/32] & (1<<aux%32)) != 0){
      write->number_elems++;
    }
  }
  write->density = (float)write->number_elems/(float)write->value_max;
}

void printfSet(Set *read){
  printf("\n%i",read->number_elems);
  printf("\n%i",read->value_max);
  printf("\n%f",read->density);
  for(int z=0;z<=read->number_elems/32+1;z++){		// laco para imprimir todos os numeros digitados
    for(int y=0;y<32;y++){
      if((read->set[z]&(1<<y)) != 0){
        printf("\n%i",((z*32)+y));
      }
    }
  }
}

int main(){
  FILE *read1 = fopen("conjunto1.txt","r");
  FILE *read2 = fopen("conjunto2.txt","r");
  FILE *write = fopen("escreva.txt","w");
  Set *conjunto1 = readSet(read1);
  Set *conjunto2 = readSet(read2);
  Set *conj_uniao = emptySet();
  unionSet(conj_uniao,conjunto1,conjunto2);
  writeSet(write,conj_uniao);
  printfSet(conj_uniao);


  return 0;
}