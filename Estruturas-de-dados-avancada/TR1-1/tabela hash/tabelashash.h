#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TABELASHASH_H
#define TABELASHASH_H

typedef struct TABELAHASH{
  int* tabela;
  int tam;
  int elem;
}tabelahash;

int divisao(int chave,int tam);

char *dobra_soma(char *chave,int tam_chave, int casas_dec);

int dobra(int chave,int tam);

int multiplicacao(int chave,int tam);

int *analise_quadradratica(int *array);

int *analise_modular(int *array);

int *analise_basica(int *array);

int hash_analise(int chave,int tam,int *analise);

int *readfile(FILE *read);

tabelahash *create_table(int tamanho);
#endif

