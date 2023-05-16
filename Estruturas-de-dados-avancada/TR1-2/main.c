#include "tabelashash.h"

int main(int argc,char** argv){
  FILE* file = fopen(argv[1], "r");
  int *array = readfile(file);
  tabelahash* tabelahash1 = create_table(100000);
  // printf("\n%i",tabelahash1->elem);
  int hash,colisoes=0;
  for(int a = 0;a<6;a++){
    hash = divisao(array[a+1],100000);
    printf("\n%i",hash);
    if(tabelahash1->tabela[hash]  == NULL){
      tabelahash1->tabela[hash] = array[a+1];
      tabelahash1->elem++;
    }else{
      colisoes++;
    }
  }
  printf("divisão\ncolisoes: %i\ntotal de: %i/%i",colisoes,tabelahash1->elem,100000);
  return 0;
}