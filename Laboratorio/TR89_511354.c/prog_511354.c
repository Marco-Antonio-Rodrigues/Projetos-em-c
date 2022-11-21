#include "TR89_511354.h"

int main(int argc,char** argv){
  FILE* file = fopen(argv[1], "r");
	FILE* file1 = fopen(argv[2], "w");
  GF *grafo1 = readfile(file);
  writeSet(file1,maior_clique(grafo1),grafo1);
  fclose(file);
  fclose(file1);
  return 0;
}