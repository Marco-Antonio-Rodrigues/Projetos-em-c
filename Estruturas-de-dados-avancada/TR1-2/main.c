#include "tabelashash.h"

int main(int argc,char** argv){
  FILE* file = fopen(argv[1], "r");
  int *array = readfile(file);
  tabelahash* tabelahash1 = create_table(100000);
  tabelahash* tabelahash2 = create_table(100000);

  int *analise = analise_quadradratica(array);
  int hash,colisoes=0;
  for(int a = 0;a<array[0];a++){
    if(tabelahash1->elem == 100000){
      break;
    }
    hash = divisao(array[a+1],100000);
    if(tabelahash1->tabela[hash]  == -1){
      tabelahash1->tabela[hash] = array[a+1];
      tabelahash1->elem++;
    }else{
      colisoes++;
    }
  }
  printf("\nDivisão\n\tcolisoes: %i\n\ttotal de: %i/%i",colisoes,tabelahash1->elem,100000);
  return 0;
}