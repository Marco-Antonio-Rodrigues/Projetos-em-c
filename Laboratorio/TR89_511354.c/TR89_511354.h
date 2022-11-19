#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct grafo{
  long long int vertices;
  long long int arestas;
  long long int **set;
  long long int *setgrau;
}GF;