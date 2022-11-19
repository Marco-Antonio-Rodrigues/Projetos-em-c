#include "TR89_511354.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GF *readfile(FILE *read){
  long long int aux, linha, coluna;
  GF *newgrafo = malloc(sizeof(GF));
  fscanf(read,"%lld %lld %lld",&newgrafo->vertices,&aux,&newgrafo->arestas);
  newgrafo->set = malloc(sizeof(long long int*)*(newgrafo->vertices+1));
  newgrafo->setgrau = malloc(sizeof(long long int)*(newgrafo->vertices+1));
  for(aux = 0 ;aux<=newgrafo->vertices;aux++){//aloquei memoria e zerei tudo
    newgrafo->set[aux] = malloc(sizeof(long long int)*(1+(newgrafo->vertices/64)));
    newgrafo->setgrau[aux]=1;
    for(int i = 0 ;i<(1+(newgrafo->vertices/64));i++){
      newgrafo->set[aux][i] = 0;
    }
  }
  //aux e so pra dizer o numero de vezes de repet
  //faz o preencimento da matriz
  for(aux = 0 ;aux<newgrafo->arestas;aux++){
    fscanf(read,"%lld %lld",&linha,&coluna);
    newgrafo->set[linha][coluna/64] = newgrafo->set[linha][coluna/64] | (1<<coluna%64);
    newgrafo->set[coluna][linha/64] = newgrafo->set[coluna][linha/64] | (1<<linha%64);
    
    newgrafo->set[linha][linha/64] = newgrafo->set[linha][linha/64] | (1<<linha%64);
    newgrafo->set[coluna][coluna/64] = newgrafo->set[coluna][coluna/64] | (1<<coluna%64);
    
    newgrafo->setgrau[linha] = (newgrafo->setgrau[linha])+1;
    newgrafo->setgrau[coluna] = (newgrafo->setgrau[coluna])+1;
  }
  return newgrafo;
}

long long int max_clique(GF *grafo){
  long long int max_clique;
  float delta = 4;
  delta = 1 + (4 *(2*grafo->arestas));
  delta = sqrt(delta);
  max_clique = (1 + delta)/2;
  if(max_clique == grafo->vertices){
    max_clique = max_clique - 1;
  }
  int numero_graus = 0;

  for(int i = max_clique; i > 0;i--){
    numero_graus = 0;
    for(int y = 1; y <= grafo->vertices;y++){
      if(grafo->setgrau[y] >= i){
        printf("%lli >= %i\n",grafo->setgrau[y],i);
        numero_graus++;
      }
    }
    if(numero_graus >= i){
      return i;
    }
  }

  printf("aqui");
  return max_clique;
}

int intersecSet(GF *grafo,int new,int *solucao){
  int aux;
  int grau;
  for(int i = 1; i <= grafo->vertices ; i++){
    if(solucao[i] == 1){
      grau = -1;
      if( ((grafo->set[new][i/64] & (1<<i%64)) != 0) && ((grafo->set[i][new/64] & (1<<new%64)) != 0)){
        for(aux = 1; aux <= grafo->vertices ; aux++){
          if( ((grafo->set[new][aux/64] & (1<<aux%64)) != 0) && ((grafo->set[i][aux/64] & (1<<aux%64)) != 0)){
            grau++;
          }
        }
      if(grau < (solucao[0])){
        printf("caiu-grau: %i\n",grau);
        return -1;
      }
      }else{
        return -1;
      }
    }
  }
  return grau;
}


int* gulosa(GF *grafo){
  int *solucao = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 1;y<=grafo->vertices;y++){
    solucao[y] = 0;
  }
  int maior;

  for(int y = 1;y<=grafo->vertices;y++){
    int maior_grau = 0;
    for(int i = 1;i<=grafo->vertices;i++){
      if(maior_grau<grafo->setgrau[i]){
        maior_grau = grafo->setgrau[i];
        maior = i;
      }
    }
    if(y == 1){
      solucao[maior] = 1;
      solucao[0] = (solucao[0]) + 1;
      grafo->setgrau[maior] = -1;
    }else{
      if(intersecSet(grafo,maior,solucao) != -1){
        solucao[maior] = 1;
        solucao[0] = (solucao[0]) + 1;
      }
        grafo->setgrau[maior] = -1;
    }
  }
  for(int i = 1;i<=grafo->vertices;i++){
      printf("solucao[%i] = %i\n",i,solucao[i]);
    }
    return solucao;
}

void writeSet(FILE *write, int *read,GF *grafo){
  fprintf(write,"%i\n",read[0]);
  for(int i = 1;i<=grafo->vertices;i++){
    if(read[i] == 1){
    fprintf(write,"%i\n",i);
    }
  }
}

int main(){
  FILE *file1 = fopen("grafo.txt","r");
  FILE *file2 = fopen("result.txt","w");
  GF *grafo1 = readfile(file1);
  printf("clique max:%lli\n",max_clique(grafo1));
  printf("\nmain:\n%lld\n",grafo1->vertices);
  printf("%lld\n",grafo1->arestas);
  // printf("result: %lli\n",(grafo1->set[1][0])&(1<<2));
  printf("result: %lli\n",grafo1->setgrau[1]);
  printf("result: %lli\n",grafo1->setgrau[2]);
  printf("result: %lli\n",grafo1->setgrau[3]);
  printf("result: %lli\n",grafo1->setgrau[4]);
  printf("result: %lli\n",grafo1->setgrau[5]);
  writeSet(file2,gulosa(grafo1),grafo1);
  return 0;
}

