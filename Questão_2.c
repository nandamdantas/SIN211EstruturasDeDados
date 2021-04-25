#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sINFO{
	char palavra[30];
	int tam;
}INFO;

typedef struct sNO{
	INFO info;
	struct sNO *dir;
	struct sNO *esq;
}NO;

NO* alocarNo(){
	return (NO*) malloc (sizeof(NO));
}

void desalocarNo(NO *q){
	free(q);
}

void inicializar (NO*ptrLista){
	ptrLista = NULL;
}

int vazia(NO*ptrLista){ //n„o utiliza ponteiro pra ponteiro porque n„o faz nenhuma alteraÁ„o no cÛdigo
   if(ptrLista == NULL){
    return 1; //lista vazia
   }
   else{
    return 0;
   }
}

INFO defineElemento(INFO elem){
	printf("\nDigite a palavra a ser inserida: ");
	scanf("%s", &elem.palavra);
	elem.tam = strlen(elem.palavra);
	return elem;
}

void inserirInicio(NO**lista, INFO elem){
        NO* novo;
        NO* aux;
       
        novo = alocarNo();
        aux = *lista;
        
        if(novo != NULL){
			 novo->info = defineElemento(elem);
			 if(vazia(aux) == 1){	//se a lista estiver vazia
		        
	            novo->esq = aux;
	            novo->dir = aux;
	         }
	         
	         else{
	         	  while(aux->esq != (*lista)){
	         	  	aux = aux->esq;
				   }
				   
				   aux->esq = novo;
				   novo->dir = aux;
				   novo->esq = (*lista);   
		     }
	    }else{
	    	printf("ERRO na alocacao do no!");
		}
}

void removerFim(NO**lista){
	NO* aux;
	NO* q;
    aux = *lista;

     if(vazia(aux)==0){ //h· elementos na lista
        while(aux->esq != *lista){
        	q= aux;
        	aux = aux->esq;
        }
		desalocarNo(aux);
		q->esq = *lista;
     }
     else{
        printf("\nERRO: Lista vazia! \n");
     }
}

void exibirInverso(NO*lista){
	NO* aux;
		
	if(vazia(lista)==0){
		aux= lista->esq;
		printf("%s ", aux->info);
		do{
			printf("\n%s - %d caracteres", aux->info.palavra, aux->info.tam);
			aux = aux->esq;
		}while(aux!= lista->esq);
	}
	else{
		printf("\nErro! Lista vazia!");
	}
}

void apagarNos(NO**lista){
	NO* aux;
	aux = *lista;
	if(vazia(aux)==1){
		desalocarNo(aux);
		*lista = NULL;
	}
	else{
		while(aux->esq != *lista){
			desalocarNo(aux);
			aux = aux->esq;
		}
	}
	aux = NULL;
}

void menu(NO* ptrL){
	
	 int opcao;
	 INFO elem;
	 
     do{
	 printf("\n-----LISTA DE PALAVRAS | MENU-----\n");
     printf("\n Digite:\n");
     printf("\n1 para inserir palavra no inicio ");
     printf("\n2 para remover palavra do final ");
     printf("\n3 para exibir palavras de tr·s pra frente ");
     printf("\n4 para encerrar (isto apagara toda a lista)\n");
     scanf("%d", &opcao);
  
        switch(opcao){
           case 1:
           	 inserirInicio(&ptrL, elem);
		     break;
           case 2:
             removerFim(&ptrL);
             break;
           case 3:
             exibirInverso(ptrL);
             break;
           case 4:
             apagarNos(&ptrL);
             break;
           default:
             printf("Digite uma op√ß√£o valida!");
             
        }
   }while(opcao!=4);
}

