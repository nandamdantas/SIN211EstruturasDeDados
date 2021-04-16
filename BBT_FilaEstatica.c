#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAMMAX 4
typedef struct sFila{
	int itens[TAMMAX];
	int inicio, fim;
}Fila;

void inicializar(Fila *ptrF){
    ptrF->inicio = TAMMAX -1;
    ptrF->fim = TAMMAX -1;
}

int vazia (Fila *ptrF){
	if(ptrF->inicio == ptrF->fim){
		return 1; //está vazia
	}
	else{
		return 0;
	}
}

int cheia (Fila *ptrF){
	if((ptrF->inicio == ptrF->fim) && ((ptrF->fim -= 1) != -1)) {
		return 1; //está cheia
	}
	else{
		return 0;
	}
}

void enfileirar(Fila*ptrF, int elem){ //inserir no final da fila
   if(ptrF->fim == TAMMAX -1){
   	    ptrF->fim = 0;
   }
   else{
   	    (ptrF->fim) ++;
   }
   if(cheia(ptrF) == 1){
   	    printf("ERRO: Fila cheia!");
   	    (ptrF->fim) --;
   	    
   	    if(ptrF->fim == -1){
   	    	ptrF->fim = TAMMAX -1;
   	    return;	
		}
   }
   
   ptrF->itens[ptrF->fim] = elem;

}

int desenfileirar(Fila *ptrF){
	int aux = 0;
	
	if(vazia(ptrF)!=1){
		 if(ptrF->inicio == TAMMAX -1){
		     ptrF -> inicio = 0;
	     }
	     else{
	     	(ptrF->inicio)++;
		 }
		 
		 aux = ptrF->itens[ptrF->inicio];
   	}
	return aux;
}

int impressaoClassica(Fila *ptrF){
	
	int aux = 0;
	
	for(aux=0; vazia(ptrF)==1; aux++ ){
	
     	if(vazia(ptrF)!=1){
		    if(ptrF->inicio == TAMMAX -1);
		      ptrF -> inicio = 0;
	    }
	    else{
	     	(ptrF->inicio)++;
		}
		 
		 aux = ptrF->itens[ptrF->inicio];
		 return aux;
	    (ptrF->fim) --;
	}
	
}

void exibir(Fila *ptrF){
	int i;
	if(vazia(ptrF) == 1){
		printf("ERRO: Lista vazia!");
	}
	else{
	    for(i=ptrF->inicio; i<ptrF->fim; i++){
		   printf("%d ", ptrF->itens[i]);
	    }
    }
	
}
void menu(){

  int opcao;
  int elem;
  Fila* ptrF;
   
  printf("\n-----FILA ESTÁTICA | MENU-----\n");
  printf("\n Digite:\n");
  printf("1 para inserir elemento na fila\n");
  printf("2 para remover um elemento da pilha\n");
  printf("3 para exibir elementos da lista usando a impressao nao classica\n");
  printf("4 para exibir todos os elementos da lista usando a representação classica\n");
  scanf("%d", &opcao);

  switch(opcao)
  case 1:
  	  inicializar(ptrF);
  	  printf("Qual elemento deseja inserir? ");
  	  scanf("%d", &elem);
  	  enfileirar(ptrF, elem);
      break;
      
  case 2:
      desenfileirar(ptrF);
      break;
      
  case 3:
      exibir(ptrF);
      break;
      
  case 4:
      impressaoClassica(ptrF);
      break;
      
   default:
      printf("Digite uma opção valida!");
      break;
}




