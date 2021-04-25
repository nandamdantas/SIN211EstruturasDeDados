#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define TAMMAX 10 
typedef struct sDeque{
	int itens[TAMMAX];
	int inicio;
	int fim;
}Deque;

void inicializar(Deque *ptrD){
	ptrD->inicio = TAMMAX -1;
	ptrD->fim = TAMMAX -1;
}

int vazia(Deque*ptrD){
	if(ptrD->inicio == ptrD->fim){
		return 1; //deque vazia 
	}
	else{
		return 0;
	}
}

int cheia (Deque *ptrD){
	if((ptrD->inicio == ptrD->fim) && ((ptrD->fim -= 1) != -1)) {
		return 1; //está cheia
	}
	else{
		return 0;
	}
}

void inserirInicio(Deque *ptrD, int elem){
	if(ptrD->inicio == 0){
		ptrD->inicio == TAMMAX - 1;
	}
	else{
		(ptrD->inicio)--;
	}
	if(cheia(ptrD) == 1){
		printf("\nErro: Deque cheia.\n");
		ptrD->inicio = (ptrD->inicio +1)%TAMMAX;
	}
	ptrD->itens[(ptrD->inicio + 1) % TAMMAX] = elem;
}

void inserirFim(Deque *ptrD, int elem){
	if(ptrD->fim == TAMMAX -1){
   	    ptrD->fim = 0;
   }
   else{
   	    (ptrD->fim) ++;
   }
   if(cheia(ptrD) == 1){
   	    printf("ERRO: Fila cheia!");
   	    (ptrD->fim) --;
   	    
   	    if(ptrD->fim == -1){
   	    	ptrD->fim = TAMMAX -1;
   	    return;	
		}
   }
   
   ptrD->itens[ptrD->fim] = elem;

}



int removerInicio(Deque *ptrD){
	int aux = 0;
	
	if((vazia(ptrD))==0){
		 if(ptrD->inicio == TAMMAX -1){
		     ptrD -> inicio = 0;
	     }
	     else{
	     	(ptrD->inicio)++;
		 }
		 
		 aux = ptrD->itens[ptrD->inicio];
   	}
	return aux;
}

int removerFim(Deque*ptrD){
	int aux = 0;
	
	if(vazia(ptrD)==0){
		aux = ptrD->itens[ptrD->fim];
		if(ptrD->fim == 0){
			ptrD->fim = TAMMAX -1;
		}
		else{
			(ptrD->fim)--;
		}
	}
	else{
		printf("\nERRO: Deque vazia!\n");
	}
	return aux;
}

void exibir(Deque* ptrD){
	int i;
	for(i=0; i<TAMMAX; i++){
		printf("\t%d  ", ptrD->itens[i]);
	}
}

void exibirClassico(Deque* ptrD){
	int i;
	for(i=0; i<TAMMAX; i++){
		printf("\t%d  ", ptrD->itens[i]);
		removerInicio(ptrD);
	}
}


void menu(Deque* ptrD){
	 int opcao = 0;
	 int elem;
	 
     while(opcao!=7){
	 printf("\n-----DEQUE ESTÁTICA | MENU-----\n");
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
