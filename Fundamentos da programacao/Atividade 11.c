// Por: Marco Antonio Rodrigues Gomes de Souza

// Q11- Faça um programa que armazene em um arquivo o nome
// da disciplina (digitada) e mais nome de 3 alunos a serem digitados.
// Deve haver uma opção para mostrar o que está dentro do arquivo.

#include <stdio.h>

int main(){

    FILE *documento;
    char disciplina[2000],aluno1[1000],aluno2[1000],aluno3[1000],c[1000],escolha[2];

    documento = fopen("documento.txt","w");

    printf("=-=-=-=-=-=-=-=-=-=| Cadastro de disciplina |=-=-=-=-=-=-=-=-=-=\n");

    printf("Digite o nome da disciplina: ");
    fgets(disciplina, 10000, stdin);

    printf("\nDigite o nome do aluno1: ");
    fgets(aluno1, 1000, stdin);

    printf("\nDigite o nome do aluno2: ");
    fgets(aluno2, 10000, stdin);

    printf("\nDigite o nome do aluno3: ");
    fgets(aluno3, 10000, stdin);

    fprintf(documento,"%s",disciplina);
    fprintf(documento,"\n%s",aluno1);
    fprintf(documento,"\n%s",aluno2);
    fprintf(documento,"\n%s",aluno3);

    fclose(documento);

    printf("Quer ver o que esta escrito no arquivo?[s/n]\n:");
    scanf("%s",escolha);
    


    if ((escolha[0] == 's')||(escolha[0] == 'S')){
        documento = fopen("documento.txt","r");
        printf("\nConteudo do arquivo\n");
        while (fgets(c,1000,documento) != NULL){
            printf("\t\t\t%s",c);
        }
        printf("\n");
        fclose(documento);
    }

    return 0;
}