//  Crie um programa com 5 threads usando laço e passe para cada uma 
// o nome da respectiva thread. Cada thread dorme por 10 segundos de 
// 1 em 1 segundo. Cada thread retorna ao termino um código de ERRO 
// caso o seu nome não inicie com letra maiúscula, e SUCESSO caso 
// inicie.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>

#define N_THREADS 5

int ERRO_TH = 111;
int SUCESSO_TH = 222;

int function_time(char *name){
  for(int i=1;i<=10;i++){
    printf("\npassando: %s",name);
    sleep(1);
  }
  if isupper(name[0]){
    return SUCESSO_TH;
  }
  return ERRO_TH;
}

int main(){
  pthread_t *threads = malloc(sizeof(pthread_t)*N_THREADS);
  
  char * name = "task";
  char * name2 = "TASK";

  for(int i = 0;i<N_THREADS;i++){
    if(i%2 == 0){
      pthread_create(&threads[i],NULL,(void *) function_time,(void *) name);
    }else{
      pthread_create(&threads[i],NULL,(void *) function_time,(void *) name2);
    }
  }
  int result;
  for (int i = 0;i<N_THREADS;i++){
    pthread_join(threads[i],(void*)&result);
    printf("\n%i",result);
  }

  return 0;
}


