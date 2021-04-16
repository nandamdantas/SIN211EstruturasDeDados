#include <stdio.h>
#include <stdlib.h>

struct ELEMENTO_FILA{
	int info;
	struct ELEMENTO_FILA *prox;
};

typedef struct {
	struct ELEMENTO_FILA *inicio;
	struct ELEMENTO_FILA *final;
} FILA;

// Inicializa a fila como vazia
void init(FILA *f) {
	f->inicio = NULL;
	f->final = NULL;
}

// Verifica se a fila está vazia
int empty(FILA *f) {
	return (f->inicio == NULL && f->final == NULL);
}

// Enfileirar elementos no fim da fila 
void insert(FILA *f, int elemento) {
	struct ELEMENTO_FILA *novo = (struct ELEMENTO_FILA*) malloc(sizeof(struct ELEMENTO_FILA));
	
	novo->info = elemento;
	novo->prox = NULL;
	
	if(f->final != NULL){
		f->final->prox = novo;
	}
	f->final = novo;
	if(f->inicio == NULL){
		f->inicio = f->final;
	}
}

// Desenfileirar elemento do inicio da fila
int deletar(FILA *f) {
	if (empty(f)) {
		printf("Fila vazia!");
		return -1;
	} else {
		int valorInicio = f->inicio->info;
		struct ELEMENTO_FILA *aux = f->inicio;
		f->inicio = f->inicio->prox;
		free(aux);
		if(f->inicio == NULL){
			f->final = f->inicio;
		}
		return valorInicio;
	}
}
