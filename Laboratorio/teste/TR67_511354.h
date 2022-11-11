#include <stdio.h>
#include <stdlib.h>

#ifndef TR67_511354
#define TR67_511354

typedef struct set{
  int number_elems;
  int value_max;
  float density;
  int *set;
}Set;

// retorna um set * que foi baseado no fb
// Set* B = readSet(fb); cria o conjunto B lendo o fb 
Set *readSet(FILE *read);

// retorna um set * vazio
// Set* C = emptySet(); cria o conjunto C como um conjunto vazio
Set *emptySet();

// Faz a copiar dos dados de um arquivo para o outro
// o da esquerda recebe o da direita
// void writeSet(fd, D); escreve o conjunto D no arquivo fd
void writeSet(FILE *write, Set *read);

// Compara os arquivos read1 e read2 e escreve a uniao no arquivo write
// void unionSet(C,A,B);	C Ã© a uniÃ£o dos conjuntos A e B
void unionSet(Set *write,Set *read1,Set *read2);

// Compara os arquivos read1 e read2 e escreve a interseccao no arquivo write
// void intersecSet(D,A,B);	D Ã© a intersecao dos conjuntos A e B
void intersecSet(Set *write,Set *read1,Set *read2);

void printfSet(Set *read);

#endif