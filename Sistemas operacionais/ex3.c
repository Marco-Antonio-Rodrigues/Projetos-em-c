//  Refaça o exemplo 1 para que a thread tarefa1 retorne um código de 
// sucesso e a thread tarefa2 retorne um código de erro.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t1,t2;

int ERRO_TH = 111;
int SUCESSO_TH = 222;
	
void * codigo_t1(){
	
	for(int i=1;i<=10;i++){
		printf("Tarefa 1: Passando %d segundos\n",i);
		sleep(1);
	}
	
	return ((void*) &ERRO_TH);
	
}

void codigo_t2(){
	for(int i=1;i<=15;i++){
		printf("Tarefa 2: Passando %d segundos\n",i);
		sleep(1);
	}	
	
	pthread_exit(&SUCESSO_TH);
}

int main(void){
	int * cod1, *cod2;
	pthread_create(&t1, NULL, (void *) codigo_t1,NULL);
	pthread_create(&t2, NULL, (void *) codigo_t2,NULL);
	
	pthread_join(t1, (void**) &cod1);
	pthread_join(t2, (void**) &cod2);
	
	printf("Retorno da Tarefa 1: %d \nRetorno da Tarefa 2: %d\n",*cod1,*cod2);
	printf("Fim\n");
	return 0;
}