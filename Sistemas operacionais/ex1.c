// Crie duas threads, tarefa1 e tarefa2, que esperam a passagem de 10 e 
// 15 segundos respectivamente imprimindo uma mensagem de 
// segundo em segundo
// on windows run with wsl.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t1,t2;
	
void codigo_t1(){
	
	for(int i=1;i<=10;i++){
		printf("Tarefa 1: Passando %d segundos\n",i);
		sleep(1);
	}
	
}

void codigo_t2(){
	for(int i=1;i<=15;i++){
		printf("Tarefa 2: Passando %d segundos\n",i);
		sleep(1);
	}	
}

int main(void){
	
	pthread_create(&t1, NULL, (void *) codigo_t1,NULL);
	pthread_create(&t2, NULL, (void *) codigo_t2,NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("Fim\n");
	return 0;
}