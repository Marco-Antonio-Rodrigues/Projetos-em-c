#include "tabelashash.h"

int main(int argc,char** argv){
  FILE* file = fopen(argv[1], "r");
  int *array = readfile(file);
  tabelahash* tabelahash1 = create_table(100000);

  int *analise = analise_basica(array);
  int hash,colisoes=0;
  for(int a = 0;a<array[0];a++){
    if(tabelahash1->elem == 100000){
      break;
    }
    hash = hash_analise(array[a+1],100000,analise);
    if(tabelahash1->tabela[hash]  == -1){
      tabelahash1->tabela[hash] = array[a+1];
      tabelahash1->elem++;
    }else{
      colisoes++;
    }
  }
  printf("\nAnal.basica\n\tcolisoes: %i\n\ttotal de: %i/%i",colisoes,tabelahash1->elem,100000);
  return 0;
}