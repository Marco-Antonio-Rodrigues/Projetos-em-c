// Escreva um programa que usando um laço crie 10 threads onde cada 
// uma recebe um parâmetro de acordo um vetor de parâmetros 
// montado da seguinte forma

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N_THREADS 10

pthread_t t[N_THREADS];
	
void codigo_tarefa(int * p){
	
	for(int i=1;i<=*p;i++){
		printf("Tarefa 1: Passando %d segundos\n",i);
		sleep(1);
	}
	
}


int main(void){
	
	int param_threads[N_THREADS];
	
	for(int i=0; i<N_THREADS;++i)
		param_threads[i] = 5 + i;
	
	for(int i=0; i<N_THREADS;++i)
		pthread_create(&t[i], NULL, (void *) codigo_tarefa,(void*) &param_threads[i]);
	
	for(int i=0; i<N_THREADS;++i)
		pthread_join(t[i], NULL);
	
	
	printf("Fim\n");
	return 0;
}