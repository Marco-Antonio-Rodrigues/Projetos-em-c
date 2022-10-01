#include <stdlib.h>
#include <stdio.h>

struct no{
    int id;
    int sexo;
    int num_filhotes;
    struct no *prox;
    struct no *ant;
};

typedef struct no NO;