// Crie um programa que tenha duas threads onde, a thread tarefa1 
// recebe como parâmetro uma struct abaixo e a thread tarefa 2 recebe 
// um inteiro.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t1,t2;

struct param_t{
	int nst;
	char * nome;
};


void codigo_t1(struct param_t * p){
	
	for(int i=1;i<=p->nst;i++){
		printf("Tarefa 1: Passando %d segundos\n",i);
		sleep(1);
	}
	
}

void codigo_t2(int * t){
	for(int i=1;i<=*t;i++){
		printf("Tarefa 2: Passando %d segundos\n",i);
		sleep(1);
	}	
}

int main(void){
	
	struct param_t param;
	param.nst = 5;
	param.nome = "TAREFA 1";
	
	int param2 = 12;
	
	pthread_create(&t1, NULL, (void *) codigo_t1,(void*) &param);
	pthread_create(&t2, NULL, (void *) codigo_t2,(void *) &param2);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("Fim\n");
	return 0;
}