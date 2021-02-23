#include <stdio.h>
#include <stdlib.h>

#define TAML 50
typedef struct sLista{
    int inteiros [TAML];
    int n;

}LISTA;

void lista_inicializar(LISTA *ptrL){
    ptrL -> n = -1;
}

int lista_cheia(LISTA *ptrL){
   if(ptrL->n+1 == TAML){
    return 1; //Lista Cheia
   }
   else{
    return 0;
   }
}

int lista_vazia(LISTA *ptrL){
   if(ptrL->n < 0){
    return 1; //Lista Vazia
   }
   else{
    return 0;
   }
}

int lista_inserirfim(LISTA *ptrL, int elem){
   if (lista_cheia(ptrL) == 0){
    ptrL -> n+1 = elem;
    ptrL -> n += 1;
   }
   else{
    printf("Erro! Lista cheia!");
   }
}

int lista_inserir(LISTA *ptrL, int k, int elem){
    if(lista_cheia(ptrL)== 0){
     if (k>=0)&&(k<=n){

       for(int i = (ptrL->n+1); i>k; i--){
         ptrL->inteiros[n] = ptrL->inteiros[n-1];
       }
      ptrL->inteiros[k] = elem;
      ptrL->n = ptrL->n+1;
     }
     else{
        printf("Erro!Posicao invalida!");
        return 1;
     }
    }
    else{
        printf("Erro!Lista Cheia!");
    }
    else{
        return 0;
    }
}
int lista_remover(LISTA *ptrL, int k){
    if(lista_vazia(ptrL)==0){
        if(k>0 && k<TAML){
          for(int i=k; i<TAML;i++){
           ptrL->inteiros[k] = prtL->inteiros[k+1];
          }
          prtL->n= ptrL->n-1;
        }
        else{
            printf("Erro!Posicao invalida!");
            return 1;
        }
        return 0;
     }
     else {
        return 1;
     }
}

int lista_modificar(LISTA *ptrL, int k){
     if(lista_vazia(ptrL)==0){
        if(k>0 && k<TAML){
            ptrL->inteiros[k] = elem;
        }
        else{
            printf("Erro!Posicao invalida!");
            return 1;
        }
        return 0;
     }
     else {
        return 1;
     }
}

int lista_pesquisar(LISTA *ptrL, int elem){
     for(int i=0, i < prtL->n, i++){
        if(ptrL->inteiros[i] == elem){
            return i;
        }
     }
     else{
        return 1;
     }
}

void menu(){
  int k;
  int opcao;
  int elem;

  printf("\n-----LISTA ESTÁTICA | MENU-----\n");
  printf("\n Digite:\n");
  printf("1 para inicializar a lista estática\n");
  printf("2 para inserir elemento no fim da lista estática\n");
  printf("3 para inserir elemento na posicao 'k' da lista estática\n");
  printf("4 para remover elemento da lista estática\n");
  printf("5 para modificar elemento da posicao 'k' da lista estática\n");
  scanf("%d", &opcao);

  switch(opcao)
  case 1:
      lista_inicializar(&L);
      break;
  case 2:
      printf("Digite o elemento a ser inserido na lista de inteiros:");
      scanf("%d", elem);
      lista_inserirfim(&L, elem);
      break;
  case 3:
      printf("Digite o elemento a ser inserido na lista de inteiros:");
      scanf("%d", elem);
      printf("Digite o indice da posicao em que o elemento deve ser inserido:");
      scanf("%d", &k);
      lista_inserir(&L, k);
      break;
  case 4:
      printf("Digite o indice da posicao do elemento a ser removido da lista de inteiros:");
      scanf("%d", k);
      lista_remover(&L, k);
      break;
  case 5:
      printf("Digite o indice da posicao do elemento a ser modificado na lista de inteiros:");
      scanf("%d", k);
      lista_modificar(&L, k);
      break;
  default
      printf("Digite uma opção valida!");
}
