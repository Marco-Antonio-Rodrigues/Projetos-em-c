#include "tabelashash.h"

int divisao(int chave,int tam){
  int hash = chave % tam;
  return hash;
}

char *dobra_soma(char *chave,int tam_chave, int casas_dec){
  if(tam_chave > casas_dec){
    char *part1 = malloc(sizeof(char) * (casas_dec));
    char *part2 = malloc(sizeof(char) * (tam_chave-casas_dec));
    char *c = malloc(sizeof(char) * 2);
    int j = 1, aux1, aux2;
    for(int i=(casas_dec-1);i>-1;i--){
        part1[i] = chave[(tam_chave-j)]; j++;
    }
    for(int i= 0;i < (tam_chave-casas_dec);i++){ part2[i] = chave[i]; }
    char *soma = dobra_soma(part2,(tam_chave-casas_dec),casas_dec);
    j = (strlen(soma)-1);
    for(int i = 0;i< strlen(soma);i++){
      c[0] = '\0',c[1] = '\0';
      c[0] = part1[i]; aux1 = atoi(c);
      c[0] = soma[j]; aux2 = atoi(c);
      sprintf(c, "%i", aux1 + aux2);
      if((aux1+aux2) > 9){part1[i] = c[1]; }
      else{part1[i] = c[0];}
      j--;
    }
    return part1;
  }
  return chave;
}

int dobra(int chave,int tam){
  int casas_dec = 0,tam_chave = 0, aux = chave;
  while ((tam-1) > 0){ tam /= 10; casas_dec++;}
  if(aux == 0)tam_chave = 1;
  while (aux > 0){ aux /= 10; tam_chave++;}
  if(tam_chave > casas_dec){
    char *chave_string = malloc(sizeof(char) * (tam_chave));
    sprintf(chave_string, "%i", chave);
    return atoi(dobra_soma(chave_string,tam_chave,casas_dec));
  }else{
     return chave;
  }
}

int multiplicacao(int chave,int tam){
  float frac = chave * 0.317;
  return (int)((frac - ((int)frac))*tam);
}

int *analise_quadradratica(int chave,int tam,int *array){
  int casas_dec = 0,tam_chave = 0;
  while ((tam-1) > 0){ tam /= 10; casas_dec++;}
  int arrayn[10],aux;
  char *digito = malloc(sizeof(char) * 7);
  char *aux_char = malloc(sizeof(char));
  float *desvio = malloc(sizeof(float) * 7);
  for(int c = 0;c<7;c++){    //to o digito primeiro, segundo...
    for (int n= 0;n<10;n++){//para n 0 a 9
      arrayn[n] = 0;
      for(int i=1;i<((array[0])+1);i++){// elem d array
        sprintf(digito, "%i", array[i]); //num to char
        if(c < strlen(digito)){
          aux_char[0] = digito[c];
          aux = atoi(aux_char); //char to num
          if(aux == n) {arrayn[n]++;};
        }
      }
    }
  desvio[c] = 0;
  for(int n=0;n<10;n++){
  desvio[c] =  desvio[c]+(((arrayn[n])-(((float)array[0])/10)) * ((arrayn[n])-(((float)array[0])/10)));
  }
  }
  float swap;
  int troca,j;
  int *analise = malloc(sizeof(int) * 7);
  for(int i=0;i<7;i++){
    analise[i] = i;
    printf("\ndesvio[%i]: %f",i,desvio[i]);
  }
  for(int i = 0; i < 6;i++){ //for que adiciona
    for(j = i; j < 7;j++){
      if(desvio[i] > desvio[j]){
        swap = desvio[j];
        desvio[j] = desvio[i];
        desvio[i] = swap;
        troca = analise[i];
        analise[i] = analise[j];
        analise[j] = troca;
      }
    }
  }
  return analise;
}

int hash_analise_quadratica(int chave,int casas_dec,int *analise){
  char *aux_char = malloc(sizeof(char));
  char *digito = malloc(sizeof(char) * 7);
  char *hash = malloc(sizeof(char) * 7);
  int hash_final;
  int copia_analise[7];
  for(int a = 0;a<7;a++){
    copia_analise[a] = analise[a];
  }
  for(int c = 0;c<casas_dec;c++){    //to o digito primeiro, segundo...
    for(int g = c;g<7;g++){
        sprintf(digito, "%i", chave); //num to char
        if(copia_analise[g] < strlen(digito)){
          aux_char[c] = digito[copia_analise[g]];
          copia_analise[g] = 1000;
          break;
        }
    }
  }
    hash_final = atoi(aux_char); //char to num
    printf("\nfunc hash:%i para chave: %i",hash_final,chave);
}

int *analise_modular(int chave,int tam,int *array){
  int casas_dec = 0,tam_chave = 0;
  while ((tam-1) > 0){ tam /= 10; casas_dec++;}
  int arrayn[10],aux;
  char *digito = malloc(sizeof(char) * 7);
  char *aux_char = malloc(sizeof(char));
  float *desvio = malloc(sizeof(float) * 7);
  for(int c = 0;c<7;c++){    //to o digito primeiro, segundo...
    for (int n= 0;n<10;n++){//para n 0 a 9
      arrayn[n] = 0;
      for(int i=1;i<((array[0])+1);i++){// elem d array
        sprintf(digito, "%i", array[i]); //num to char
        if(c < strlen(digito)){
          aux_char[0] = digito[c];
          aux = atoi(aux_char); //char to num
          if(aux == n) {arrayn[n]++;};
        }
      }
    }
  desvio[c] = 0;
  for(int n=0;n<10;n++){
  if(((arrayn[n])-(((float)array[0])/10)) >= 0){
    desvio[c] =  desvio[c]+((arrayn[n])-(((float)array[0])/10)); 
  }else{
    desvio[c] =  desvio[c]+((-1.0) * (arrayn[n])-(((float)array[0])/10));
  }
  }
  }
  float swap;
  int troca,j;
  int *analise = malloc(sizeof(int) * 7);
  for(int i=0;i<7;i++){
    analise[i] = i;
    printf("\ndesvio[%i]: %f",i,desvio[i]);
  }
  for(int i = 0; i < 6;i++){ //for que adiciona
    for(j = i; j < 7;j++){
      if(desvio[i] > desvio[j]){
        swap = desvio[j];
        desvio[j] = desvio[i];
        desvio[i] = swap;
        troca = analise[i];
        analise[i] = analise[j];
        analise[j] = troca;
      }
    }
  }
  return analise;
}

int hash_analise_modular(int chave,int casas_dec,int *analise){
  char *aux_char = malloc(sizeof(char));
  char *digito = malloc(sizeof(char) * 7);
  char *hash = malloc(sizeof(char) * 7);
  int hash_final;
  int copia_analise[7];
  for(int a = 0;a<7;a++){
    copia_analise[a] = analise[a];
  }
  for(int c = 0;c<casas_dec;c++){    //to o digito primeiro, segundo...
    for(int g = c;g<7;g++){
        sprintf(digito, "%i", chave); //num to char
        if(copia_analise[g] < strlen(digito)){
          aux_char[c] = digito[copia_analise[g]];
          copia_analise[g] = 1000;
          break;
        }
    }
  }
    hash_final = atoi(aux_char); //char to num
    printf("\nfunc hash:%i para chave: %i",hash_final,chave);
}

int *readfile(FILE *read){
  int aux;
	fscanf(read,"%i",&aux);
  int* array = malloc(sizeof(int)*(aux+1));
	array[0] = aux;
  for(aux = 1 ;aux <= array[0];aux++){  //aux e so pra dizer o numero de vezes de repet faz o preencimento da matriz
    fscanf(read,"%i ",&array[aux]);
  }
  return array;
}

tabelahash *create_table(int tamanho){
  tabelahash *newtable = malloc(sizeof(tabelahash));
  newtable->tam = tamanho;
  newtable->elem = 0;
  newtable->tabela = malloc(sizeof(int) * 100000);
  for(int i;i<100000;i++){
  (newtable->tabela[i]) = NULL;
  }
  return newtable;
}