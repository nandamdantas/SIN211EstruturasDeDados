#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMP 10

typedef struct sPilha{
	char itens[TAMP];
	int topo;
}Pilha;

void inicializarTopo(Pilha *ptrP){
	
	ptrP -> topo = -1;
}

int vazia(Pilha *ptrP){
	if(ptrP -> topo == -1)
		return 1;   //pilha vazia
	return 0;
}

int cheia (Pilha *ptrP){
	if((ptrP -> topo) ==TAMP)
	    return 1; //pilha cheia
	return 0;
}

void push (Pilha *ptrP, char elem){ //empilhar
	if(cheia(ptrP)==1){
		printf("\nERRO: pilha cheia!\n");
	}
	else{
		(ptrP -> topo) ++;
		ptrP -> itens[ptrP->topo] = elem;
	}
}

int pop (Pilha *ptrP){ //desempilhar
	int q;
	if(vazia(ptrP) == 1){
		printf("\nERRO: pilha vazia!\n");
		return -1;
	}
	else{
		q = ptrP -> itens[ptrP->topo];
		(ptrP -> topo) --;
		return q;
	}
	
}

int stacktop (Pilha *ptrP){ //retornar topo
     if(vazia(ptrP) == 1){
     	printf("\nERRO:Pilha vazia!\n");
     	return -1;
	 }
	 else{
	 	return (ptrP->topo);
	 }
}
