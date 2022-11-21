#include "TR89_511354.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GF *readfile(FILE *read){
  int aux, linha, coluna;
  GF *newgrafo = malloc(sizeof(GF));
  fscanf(read,"%i %i %i",&newgrafo->vertices,&aux,&newgrafo->arestas);
  newgrafo->set = malloc(sizeof(int*)*(newgrafo->vertices+1));
  newgrafo->setgrau = malloc(sizeof(int)*(newgrafo->vertices+1));
  for(aux = 0 ;aux<=newgrafo->vertices;aux++){//aloquei memoria e zerei tudo
    newgrafo->set[aux] = malloc(sizeof(int)*(1+(newgrafo->vertices/32)));
    newgrafo->setgrau[aux]=1;//ja comeca com pelo menos 1 grau que e ele mesmo
    for(int i = 0 ;i<(1+(newgrafo->vertices/32));i++){
      newgrafo->set[aux][i] = 0;
    }
  }
  for(aux = 0 ;aux<newgrafo->arestas;aux++){  //aux e so pra dizer o numero de vezes de repet faz o preencimento da matriz
    fscanf(read,"%i %i",&linha,&coluna);
    newgrafo->set[linha][coluna/32] = newgrafo->set[linha][coluna/32] | (1<<coluna%32);
    newgrafo->set[coluna][linha/32] = newgrafo->set[coluna][linha/32] | (1<<linha%32);
    newgrafo->set[linha][linha/32] = newgrafo->set[linha][linha/32] | (1<<linha%32);
    newgrafo->set[coluna][coluna/32] = newgrafo->set[coluna][coluna/32] | (1<<coluna%32);
    
    newgrafo->setgrau[linha] = (newgrafo->setgrau[linha])+1;
    newgrafo->setgrau[coluna] = (newgrafo->setgrau[coluna])+1;
  }
  return newgrafo;
}

int max_clique(GF *grafo){
  int max_clique;
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
        numero_graus++;
      }
    }
    if(numero_graus >= i){
      return i;
    }
  }
  return max_clique;
}

int intersecSet(GF *grafo,int new,int *solucao){
  int aux;
  int grau;
  for(int i = 1; i <= grafo->vertices ; i++){
    if(solucao[i] == 1){
      if( ((grafo->set[new][i/32] & (1<<i%32)) != 0) && ((grafo->set[i][new/32] & (1<<new%32)) != 0)){//verifica se eles sao conectados pra dps continuar
        grau = -1;
        for(aux = 1; aux <= grafo->vertices ; aux++){
          if( ((grafo->set[new][aux/32] & (1<<aux%32)) != 0) && ((grafo->set[i][aux/32] & (1<<aux%32)) != 0)){
            grau++;
          }
        }
      if(grau < (solucao[0])){
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
  for(int y = 1;y<=grafo->vertices;y++){ solucao[y] = 0;}

  int maior;
  for(int y = 1;y<=grafo->vertices;y++){
    int maior_grau = 0;
    for(int i = 1;i<=grafo->vertices;i++){
      if(maior_grau<grafo->setgrau[i]){
        maior_grau = grafo->setgrau[i];
        maior = i;
      }
    }
    if(y == 1){ //caso seja o primeiro item a adicionar
      solucao[maior] = 1;
      solucao[0] = solucao[0] + 1; //numero de elementos do clique
      grafo->setgrau[maior] = -1;
    }else{
      if(intersecSet(grafo,maior,solucao) != -1){
        solucao[maior] = 1; 
        solucao[0] = solucao[0] + 1;//numero de elementos do clique
      }
        grafo->setgrau[maior] = -1;
    }
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
  FILE *file1 = fopen("hamming6-4.mtx","r");
  FILE *file2 = fopen("result.txt","w");
  GF *grafo1 = readfile(file1);
  printf("\nmain:\n%i\n",grafo1->vertices);
  printf("%i\n",grafo1->arestas);
  printf("clique max:%i\n",max_clique(grafo1));
  // for(int i = 1;i<=grafo1->vertices; i++){
  // printf("grau %i: %i\n",i,grafo1->setgrau[i]);
  // }
  writeSet(file2,gulosa(grafo1),grafo1);
  return 0;
}

