#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct sNo{
	int info;
	struct sNo *esq;
	struct sNo *dir;
}NO;

typedef struct sDeque{
	NO *inicio;
	NO *fim;
}Deque;

NO* alocarNo(){
	return (NO*)malloc(sizeof(NO));
}

void desalocarNO(NO *q){
	free(q);
}

void inicializar(Deque *ptrD){
	ptrD->inicio = NULL;
	ptrD->fim = NULL;
}

int vazia (Deque *ptrD){
	if((ptrD->inicio== NULL)){
		return 1; //lista vazia
	}
	else{
		return 0;
	}
}
void inserirInicio(Deque *ptrD, int elem){
	NO* novo;
	novo = alocarNo();
	
	if(novo != NULL){
		if(vazia(ptrD) == 1){
		   ptrD->inicio = novo;
		   ptrD->fim = novo;
		}
		else{ //se há elementos
			novo->dir = ptrD->inicio;
			(ptrD->inicio)->dir = novo;
		}
	}
	else{
		printf("\nERRO na alocação do nó!");
	}
}

void inserirFim(Deque *ptrD, int elem){
	NO* novo;
	novo = alocarNo();
	
	if(novo != NULL){
		novo->info = elem;
		novo->dir = NULL;
		
	    if(vazia(ptrD)==1){
		   ptrD->inicio = novo;
		   ptrD->fim = novo;
		}
		else{
			(ptrD->fim)->dir = novo;
			novo->esq = ptrD->fim;
			ptrD->fim = novo;
		}
	}
	else{
		printf("\nERRO na alocação do nó!");
	}
}

int removerInicio(Deque *ptrD){
	NO* aux;
	int x=0;
	
	if(vazia(ptrD) == 0){
		
		aux = (ptrD->inicio)->dir;
		x = (ptrD->inicio)->info;
		
		desalocarNo(ptrD->inicio);
		ptrD->inicio = aux;
		
		if(ptrD->inicio !=NULL){
			(ptrD->inicio)->esq = NULL;
		}
		else{
			ptrD->fim = NULL;
		}
    }
	else{
		printf("\nERRO: Deque vazia!");
	}
return x;	
}

int removerFim(Deque *ptrD){
	NO* aux;
	int x=0;
	
	if(vazia(ptrD) == 0){
		
		aux = (ptrD->fim)->esq;
		x = (ptrD->fim)->info;
		
		desalocarNo(ptrD->fim);
		ptrD->fim = aux;
		
		if(ptrD->fim !=NULL){
			(ptrD->fim)->dir = NULL;
		}
		else{
			ptrD->inicio = NULL;
		}
    }
	else{
		printf("\nERRO: Deque vazia!");
	}
return x;	
}

void exibirClassico(Deque *ptrD){
	if(vazia(ptrD)==0){
	    while(vazia(ptrD)!=1){
		    removerInicio(ptrD);
	    }
    }
    else{
    	printf("\nERRO: Deque vazia!");
	}
}

void exibir(Deque *ptrD){
	NO* aux;
	aux = ptrD->inicio;
	
   	if(vazia(ptrD)==0){
	    while(aux != ptrD->fim){
		    printf("%d  ", aux->info);
	    }
    }
    else{
    	printf("\nERRO: Deque vazia!");
	}
}

void menu(Deque* ptrD){
	
	 int opcao = 0;
	 int elem;
	 
     while(opcao!=7){
	 printf("\n-----DEQUE DINÂMICA | MENU-----\n");
     printf("\n Digite:\n");
     printf("\n1 para inserir elemento no inicio da deque");
     printf("\n2 para inserir elemento no final da deque");
     printf("\n3 para remover elemento do inicio ");
     printf("\n4 para remover elemento do final ");
     printf("\n5 para exibir elementos da lista com a impressão NÃO CLÁSSICA ");
     printf("\n6 para exibir elementos da lista usando a representação clássica ");
     printf("\n7 para encerrar (isto apagara toda a lista)\n");
     scanf("%d", &opcao);
  
        switch(opcao){
           case 1:
           	  inserirInicio(ptrD, elem);
		      break;
           case 2:
              inserirFim(ptrD, elem);
             break;
           case 3:
             removerInicio(ptrD);
             break;
           case 4:
             removerFim(ptrD);
             break;
           case 5:
             exibir(ptrD);
             break;
           case 6:
             exibirClassico(ptrD);
             break;
           default:
             printf("Digite uma opção valida!");
             
        }
   }
}
