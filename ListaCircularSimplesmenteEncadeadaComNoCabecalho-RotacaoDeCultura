#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//definindo o tipo Cultura
typedef struct sCultura{
	char nome[20];
	int mes;
}CULTURA;

//definindo a Lista Circular Simplesmente Encadeada com no de cabecalho
typedef struct sNo{
	CULTURA info;
	struct sNo *prox;
	int cabecalho;
}NO;


NO* alocarNo(){
	return (NO*) malloc (sizeof(NO));
}

void desalocarNo(NO *q){
	free(q);
}

NO* inicializar(NO* lista){
    lista = alocarNo();
	lista->info.mes = 0;
	strcpy(lista->info.nome, "Nome da cultura");
	lista->cabecalho = -1;
	lista->prox = lista;
	
	return lista;
}

void defineElemento(CULTURA elem){
	printf("\nQual cultura deseja plantar? ");
	scanf(" %s", &elem.nome);
	while(elem.mes<=0 || elem.mes>12){
		printf("\nMes do plantio: ");
	    scanf("%d", &elem.mes);
    }
}

int vazia(NO* lista){
	if((lista->cabecalho) == -1){
		return 1; //lista está vazia
	}
	else{
		return 0; //há itens na lista
	}
}

void inserirInicio(NO**lista, CULTURA elem){ //notação ponteiro pra ponteiro, visto que a função inserir altera a lista pipipipopopo
  NO* novo;
  NO* aux;
  aux = *lista;
  
  novo = alocarNo();
  
  if(novo != NULL){
  	defineElemento(novo->info);
  	    if(novo->info.mes == 11){ 
  		(aux->cabecalho)++;   //nó cabeçalho irá armazenar o número de plantios no mês de novembro
	    }
  		if(vazia(aux) == 1){  
		  aux->prox = novo;
		  novo->prox = aux;
	    }
	    if(aux->cabecalho <0 ){
	    	(aux->cabecalho)++;
		}
	    else{  //se houver itens na lista
	    	novo->prox = aux->prox;
		    aux->prox = novo;
	    }
  }
  else{
  	printf("\nErro na alocacao do no!\n");
  }
}

void removerFim(NO**lista){
	NO* aux;
	NO* q;
    aux = *lista;

     if(vazia(aux)==0){
        while(aux->prox != *lista){
        	q= aux;
        	aux = aux->prox;
		}
		desalocarNo(aux);
		q->prox = *lista;
     }
     else{
        printf("\nERRO: Lista vazia! \n");
     }
}


void imprimirElemento(CULTURA elem){
	printf("\nCultura: %s", elem.nome);
	printf("\nMes de plantio: %d", elem.mes);	
}


void exibir(NO*lista){
	NO* aux;
		
	if(vazia(lista) == 0){
		aux= lista->prox;
		printf("\nItens com plantio no mes de novembro: %d ", aux->cabecalho);
		do{
			imprimirElemento(aux->info);
			aux = aux->prox;
		}while(aux!= lista->prox);
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
		while(aux->prox != *lista){
			desalocarNo(aux);
			aux = aux->prox;
		}
	}
	aux = NULL;
}

void menu(NO* ptrL){
	
	 int opcao;
	 CULTURA elem;
	 
     do{
	 printf("\n-----ROTACAO DE CULTURA | MENU-----\n");
     printf("\n Digite:\n");
     printf("\n1 para inserir elemento no inicio ");
     printf("\n2 para remover elemento do final ");
     printf("\n3 para exibir elementos da lista ");
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
             exibir(&ptrL);
             break;
           case 4:
             apagarNos(&ptrL);
             break;
           default:
             printf("Digite uma opcao valida!");
             
        }
   }while(opcao!=4);
}
