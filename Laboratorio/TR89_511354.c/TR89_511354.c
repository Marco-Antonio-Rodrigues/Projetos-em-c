#include "TR89_511354.h"

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

int intersecSet(GF *grafo,int new,int *solucao){
  int aux,grau;
  for(int i = 1; i <= grafo->vertices ; i++){
    if(solucao[i] == 1){
      if( ((grafo->set[new][i/32] & (1<<i%32)) != 0) && ((grafo->set[i][new/32] & (1<<new%32)) != 0)){//verifica se eles sao conectados pra dps continuar
        grau = -1; //necessario porque se nao conta duas vezes
        for(aux = 1; aux <= grafo->vertices; aux++){
          if(((grafo->set[new][aux/32] & (1<<aux%32)) != 0) && ((grafo->set[i][aux/32] & (1<<aux%32)) != 0)){
            grau++;
          }
        }
      if(grau < solucao[0]){return -1;}
      }else{return -1;}
    }
  }
  return grau;
}

int* gulosa_inicio(GF *grafo){
  int *setgraucopy = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 0; y<=grafo->vertices;y++){
    setgraucopy[y] = grafo->setgrau[y]; 
  }
  int *solucao = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 1;y<=grafo->vertices;y++){ solucao[y] = 0;} //zerando todos os elementos
  int maior;

  for(int y = 1;y<=grafo->vertices;y++){
    int maior_grau = 0;
    for(int i = 1;i<=grafo->vertices;i++){//pecorre o vetor procurando o maior grau.
      if(maior_grau<setgraucopy[i]){
        maior_grau = setgraucopy[i];
        maior = i;
      }
    }
    if(y == 1){ //caso seja o primeiro item a adicionar
      solucao[maior] = 1;
      solucao[0] = solucao[0] + 1; //numero de elementos do clique
      setgraucopy[maior] = -1;
    }else{
      if(intersecSet(grafo,maior,solucao) != -1){
        solucao[maior] = 1; 
        solucao[0] = solucao[0] + 1;//numero de elementos do clique
      }
        setgraucopy[maior] = -1; //elimina o elemento para nao contar no proximo ciclo
    }
  }
    return solucao;
}

int* gulosa_final(GF *grafo){
  int *setgraucopy = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 0; y<=grafo->vertices;y++){
    setgraucopy[y] = grafo->setgrau[y]; 
  }
  int *solucao = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 1;y<=grafo->vertices;y++){ solucao[y] = 0;} //zerando todos os elementos
  int maior;

  for(int y = 1;y<=grafo->vertices;y++){
    int maior_grau = 0;
    for(int i = grafo->vertices;i>0;i--){//pecorre o vetor procurando o maior grau.
      if(maior_grau<setgraucopy[i]){
        maior_grau = setgraucopy[i];
        maior = i;
      }
    }
    if(y == 1){ //caso seja o primeiro item a adicionar
      solucao[maior] = 1;
      solucao[0] = solucao[0] + 1; //numero de elementos do clique
      setgraucopy[maior] = -1;
    }else{
      if(intersecSet(grafo,maior,solucao) != -1){
        solucao[maior] = 1; 
        solucao[0] = solucao[0] + 1;//numero de elementos do clique
      }
        setgraucopy[maior] = -1; //elimina o elemento para nao contar no proximo ciclo
    }
  }
    return solucao;
}

int* gulosa_meio_esq(GF *grafo){
  int *setgraucopy = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 0; y<=grafo->vertices;y++){
    setgraucopy[y] = grafo->setgrau[y]; 
  }
  int *solucao = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 1;y<=grafo->vertices;y++){ solucao[y] = 0;} //zerando todos os elementos
  int maior;

  for(int y = 1;y<=grafo->vertices;y++){
    int maior_grau = 0;
    for(int i = grafo->vertices/2;i>0;i--){//pecorre o vetor procurando o maior grau.
      if(maior_grau<setgraucopy[i]){
        maior_grau = setgraucopy[i];
        maior = i;
      }
    }
  for(int i = grafo->vertices;i>grafo->vertices/2;i--){//pecorre o vetor procurando o maior grau.
    if(maior_grau<setgraucopy[i]){
      maior_grau = setgraucopy[i];
      maior = i;
    }
  }
    if(y == 1){ //caso seja o primeiro item a adicionar
      solucao[maior] = 1;
      solucao[0] = solucao[0] + 1; //numero de elementos do clique
      setgraucopy[maior] = -1;
    }else{
      if(intersecSet(grafo,maior,solucao) != -1){
        solucao[maior] = 1; 
        solucao[0] = solucao[0] + 1;//numero de elementos do clique
      }
        setgraucopy[maior] = -1; //elimina o elemento para nao contar no proximo ciclo
    }
  }
    return solucao;
}

int* gulosa_meio_dir(GF *grafo){
  int *setgraucopy = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 0; y<=grafo->vertices;y++){
    setgraucopy[y] = grafo->setgrau[y]; 
  }
  int *solucao = malloc(sizeof(int)*(grafo->vertices+1));
  for(int y = 1;y<=grafo->vertices;y++){ solucao[y] = 0;} //zerando todos os elementos
  int maior;

  for(int y = 1;y<=grafo->vertices;y++){
    int maior_grau = 0;
    for(int i = grafo->vertices/2;i<=grafo->vertices;i++){//pecorre o vetor procurando o maior grau.
      if(maior_grau<setgraucopy[i]){
        maior_grau = setgraucopy[i];
        maior = i;
      }
    }
  for(int i = 1;i<grafo->vertices/2;i++){//pecorre o vetor procurando o maior grau.
    if(maior_grau<setgraucopy[i]){
      maior_grau = setgraucopy[i];
      maior = i;
    }
  }
    if(y == 1){ //caso seja o primeiro item a adicionar
      solucao[maior] = 1;
      solucao[0] = solucao[0] + 1; //numero de elementos do clique
      setgraucopy[maior] = -1;
    }else{
      if(intersecSet(grafo,maior,solucao) != -1){
        solucao[maior] = 1; 
        solucao[0] = solucao[0] + 1;//numero de elementos do clique
      }
        setgraucopy[maior] = -1; //elimina o elemento para nao contar no proximo ciclo
    }
  }
    return solucao;
}

int* maior_clique(GF *grafo){
  int* solucao1 = gulosa_inicio(grafo); int* solucao2 = gulosa_final(grafo);
  int* solucao3 = gulosa_meio_esq(grafo); int* solucao4 = gulosa_meio_dir(grafo);
  int* melhor_solucao; int* melhor_solucao1; int* melhor_solucao2;

  if(solucao1[0] > solucao2[0]){ melhor_solucao1 = solucao1;
  }else{ melhor_solucao1 = solucao2;}

  if(solucao3[0] > solucao4[0]){ melhor_solucao2 = solucao3;
  }else{ melhor_solucao2 = solucao4;}

  if(melhor_solucao1[0] > melhor_solucao2[0]){ melhor_solucao = melhor_solucao1;
  }else{ melhor_solucao = melhor_solucao2;}
  
  return melhor_solucao;
}

void writeSet(FILE *write, int *read,GF *grafo){
  fprintf(write,"%i\n",read[0]);
  for(int i = 1;i<=grafo->vertices;i++){
    if(read[i] == 1){
    fprintf(write,"%i\n",i);
    }
  }
}

