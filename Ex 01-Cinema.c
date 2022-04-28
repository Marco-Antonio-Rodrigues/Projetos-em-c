#include <stdio.h>

int main(){

    //POR: Marco Antonio Rodrigues Gomes de Souza
    //Esse codigo recebe algumas informações como hora e data e informar ao usuario se ele pode
    //ou não entrar no cinema.

    // Aqui temos todas as variaveis
    int horaFilme, horaChegada;
    int minutoFilme, minutoChegada;
    int horaFilmeExata, horaChegadaExata;

    printf("qual o horario do filme?");
    printf("\nhora:");
    scanf("%i",&horaFilme);
    printf("minuto:");
    scanf("%i",&minutoFilme);
    printf("Horario do Filme = %i:%i horas\n",horaFilme, minutoFilme);

    printf("\nqual horario de chegada?");
    printf("\nhora:");
    scanf("%i",&horaChegada);
    printf("minuto:");
    scanf("%i",&minutoChegada);
    printf("Horario de chegada = %i:%i horas",horaChegada, minutoChegada);

    // Aqui pegamos as horas multiplicamos por 60 para virar minutos e somamos
    //com os minutos do filme e da chegada.
    horaFilmeExata = minutoFilme + horaFilme * 60;
    horaChegadaExata = minutoChegada + horaChegada * 60;

    //se chegar adiantado ou no horário exato
     if (horaChegadaExata <= horaFilmeExata){
        if (horaFilmeExata - horaChegadaExata > 30)
                printf("\nnao pode entrar na sala");
        else
            printf("\npode entrar");
    }
    
    //se chegar atrasado
    if (horaChegadaExata > horaFilmeExata){
        if (horaChegadaExata - horaFilmeExata > 30)
                printf("\nnao pode entrar na sala");
        else
            printf("\npode entrar");
    }

    return 0;
}

// exemplo de execução:

// qual o horario do filme?
// hora:10
// minuto:20
// Horario do Filme = 10:20 horas

// qual horario de chegada?
// hora:10
// minuto:10
// Horario de chegada = 10:10 horas
// pode entrar