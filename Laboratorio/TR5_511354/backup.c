void maxHeapfy(int *a,int m,int i){
  int e,d,maior,aux;
  e = 2*i;
  d = 2*i+1;
  if(e <= m && a[i]>a[maior]){
    maior = d;
  }
  if(maior != 1){
    aux = a[i];
    a[i] = a[maior];
    a[maior] = aux;
    maxHeapfy(a,m,i);
  }
}

void addheap(int *vetor,int n){

  vetor[ultimo] = n;// add na ultima parte do vetor
  ultimo%2 if == 1 esquedar else direita //verifica de qual lado ele esta no NO pai
  vetor[ultimo/2-1] > vetor[ultimo] // if esquerda
  vetor[ultimo/2] > vetor[ultimo] // se nao
  // passo a cima e pra saber se o pai e maior que o filho
  if sim maxHeapfy(); // ate ficar ok
}

void builderMaxHeap(int *heap,int n){
  int i = a[n/2];
  maxHeapfy();
}