#include "TR67_511354.h"
#include <stdio.h>
#include <stdlib.h>
// int bits = 64;
Set *readSet(FILE *read){//ok
  unsigned long long int aux;
  Set *new_set = malloc(sizeof(Set));
  fscanf(read,"%d",&new_set->number_elems);
  fscanf(read,"%d",&new_set->value_max);
  fscanf(read,"%f",&new_set->density);
  new_set->set = (unsigned long long int*)malloc(sizeof(unsigned long long int)*(1+(new_set->value_max/64)));
  for(aux=0;aux<=new_set->value_max/64;aux++){//setando valores para garantir que sao zeros
    new_set->set[aux]= 0;
  }
  for(int i = 0;i<new_set->number_elems;i++){//preenchendo o vetor
    fscanf(read,"%llu",&aux);
    new_set->set[aux/64] = new_set->set[aux/64] | ((unsigned long long int)1<<(aux%64));
  }
  return new_set;
}

Set *emptySet(){ //cria um conjunto vazio ok ok
  Set *new_set = malloc(sizeof(Set));
  new_set->number_elems = 0;
  new_set->value_max = 0;
  new_set->density = 0;
  new_set->set = 0;
  return new_set;
}

void writeSet(FILE *write, Set *read){
  fprintf(write,"%i",read->number_elems);
  fprintf(write,"\n%i",read->value_max);
  fprintf(write,"\n%f",read->density);
  if(read->number_elems != 0){
    for(int z=0;z<=read->value_max/64+1;z++){ //laco pra escrever todos os numeros do conjunto
      for(int y=0;y<64;y++){
        if((read->set[z]&((unsigned long long int)1<<y)) != 0){
          fprintf(write,"\n%i",((z*64)+y));
        }
      }
    }
  }
}

void copySet(Set *to,Set *copy){
  to->number_elems = copy->number_elems;
  to->value_max = copy->value_max;
  to->density = copy->density;
  to->set = malloc(sizeof(unsigned long long int)*(1+(to->value_max/64)));
  for(int i=0; i<= to->value_max/64 ; i++){
    to->set[i] = copy->set[i];
  }
}

void unionSet(Set *write,Set *read1,Set *read2){
  unsigned long long int aux;
  if((read1->number_elems != 0)  && (read2->number_elems != 0)){ 
    if(read1->value_max >= read2->value_max){//read1 tem o valor maximo
      write->value_max = read1->value_max;
      write->set = malloc(sizeof(unsigned long long int)*(1+(read1->value_max/64)));
      for(aux = 0;aux<=read2->value_max/64; aux++){// adiciona os valores restantes ao write a partir do read1
        write->set[aux] = read1->set[aux] | read2->set[aux];
      }
      for(aux = read2->value_max/64 ;aux<=read1->value_max/64; aux++){// adiciona os valores restantes ao write a partir do read1
        write->set[aux] = write->set[aux] | read1->set[aux];
      }
    }else{// read2 tem o valor maximo
      write->value_max = read2->value_max;
      write->set = malloc(sizeof(unsigned long long int)*(1+(read2->value_max/64)));
      for(aux = 0;aux<=read1->value_max/64; aux++){// adiciona os valores restantes ao write a partir do read1
        write->set[aux] = read1->set[aux];
      }
      for(aux = read1->value_max/64 ;aux<=read2->value_max/64; aux++){// adiciona os valores restantes ao write a partir do read1
        write->set[aux] = write->set[aux] | read2->set[aux];
      }
    }
    //ate aqui ok -- pegamos o valor maximo -- setamos o tamanho do array -- preeenchemos o array -- fizemos a uniao
    for(aux = 0;aux<=write->value_max;aux++){
      if((write->set[aux/64] & (1<<aux%64)) != 0){
        write->number_elems++;
      }
    }
    write->density = (float)write->number_elems/(float)write->value_max;
    }else{ 
      if(read1->number_elems != 0){
        copySet(write,read1);
      }
      if(read2->number_elems != 0){
        copySet(write,read2);
      }
    }
}

void intersecSet(Set *write,Set *read1,Set *read2){
  int aux;
  if((read1->number_elems != 0)  && (read2->number_elems != 0)){ 
    if(read1->value_max <= read2->value_max){//read1 tem menor valor maximo
      for(aux = read1->value_max; aux >= 0 ; aux--){//descobrindo o valor max que tem em ambos
        if( ((read1->set[aux/64] & (1<<aux%64)) != 0) && ((read2->set[aux/64] & (1<<aux%64)) != 0)){
          write->value_max = aux;
          break;
        }
      }
      write->set = malloc(sizeof(unsigned long long int)*(1+(write->value_max/64)));
      for(aux = 0; aux <= write->value_max ; aux++){
        if( ((read1->set[aux/64] & (1<<aux%64)) != 0) && ((read2->set[aux/64] & (1<<aux%64)) != 0)){
          write->set[aux/64] = write->set[aux/64] | (1<<aux%64);
          write->number_elems++;
        }
      }
    }else{//read2 tem menor valor maximo
      for(aux = read2->value_max; aux >= 0 ; aux--){//descobrindo o valor max que tem em ambos
        if( ((read2->set[aux/64] & (1<<aux%64)) != 0) && ((read1->set[aux/64] & (1<<aux%64)) != 0)){
          write->value_max = aux;
          break;
        }
      }
      write->set = malloc(sizeof(unsigned long long int)*(1+(write->value_max/64)));
      for(aux = 0; aux <= write->value_max ; aux++){
        if( ((read1->set[aux/64] & (1<<aux%64)) != 0) && ((read2->set[aux/64] & (1<<aux%64)) != 0)){
          write->set[aux/64] = write->set[aux/64] | (1<<aux%64);
          write->number_elems++;
        }
      }
    }
    write->density = (float)write->number_elems/(float)write->value_max;
  }else{
    write->number_elems = 0;
    write->value_max = 0;
    write->density = 0;
    write->set = 0;
  }
}
