#include <stdio.h>
#include <stdlib.h>

#ifndef TR67_511354
#define TR67_511354

// struct com dados do conjunto
typedef struct set{
  int number_elems;
  int value_max;
  float density;
  unsigned long long int *set;
}Set;

// ler o arquivo passado como parametro e retorna um set
// com as informacoes do file
Set *readSet(FILE *read);

// retorna um set * vazio
Set *emptySet();

// escreve os dados do conjunto no arquivo file
void writeSet(FILE *write, Set *read);

// faz a copia de um set para o outro
void copySet(Set *to,Set *copy);

// Compara os arquivos read1 e read2 e escreve a uniao no arquivo write
void unionSet(Set *write,Set *read1,Set *read2);

// Compara os arquivos read1 e read2 e escreve a interseccao no arquivo write
void intersecSet(Set *write,Set *read1,Set *read2);


#endif