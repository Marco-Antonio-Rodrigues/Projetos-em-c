#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct grafo{
  int vertices;
  int arestas;
  int **set;
  int *setgrau;
}GF;