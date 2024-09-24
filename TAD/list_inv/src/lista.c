#include "lista.h"

typedef struct no NO;

struct no {
	ITEM *info;
	NO *prox;
};

struct lista_ {
	NO *ini, *fim;
	int tam;
};

LISTA *lista_criar() {
	LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
	assert(lista != NULL);
	lista->ini = NULL;
	lista->fim = NULL;
	lista->tam = 0;
	return lista;
}

bool lista_vazia(LISTA *lista) {
	assert(lista != NULL);
	return (lista->tam == 0);
}

int lista_tamanho(LISTA *lista) {
	assert(lista != NULL);
	return lista->tam;
}

bool lista_inserir(LISTA *lista, ITEM *chave) {
	NO *p = (NO *)malloc(sizeof(NO));
	p->info = chave;
	p->prox = NULL;
	
	if(lista_vazia(lista)) {
		lista->ini = p;
	} else {
		lista->fim->prox = p;
	}	
	lista->fim = p;
	lista->tam++;

	if(p != NULL)
		return true;
	else 
		return false;
}

bool lista_apagar(LISTA **lista) {
		if(lista != NULL){
		NO *p = (*lista)->ini;
		while (p != NULL) {
			(*lista)->ini = (*lista)->ini->prox;
			item_apagar(&(p->info));
			free(p);
			p = (*lista)->ini;
		}
		free(*lista);
		*lista = NULL;
		return true;
	}

	return false;
}

void lista_imprimir(LISTA *lista){
	assert(lista != NULL);

	for(NO* aux = lista->ini; aux->prox != NULL; aux = aux->prox)
		item_imprimir(aux->info);

	item_imprimir(lista->fim->info);
	printf("\n");
}

ITEM *lista_busca(LISTA *lista, int chave){
	ITEM* alvo;

	for(NO* aux = lista->ini; aux->prox != NULL; aux = aux->prox)
		if(item_get_chave(aux->info) == chave){
			alvo = aux->info;
			break;
		}
	
	return alvo;
}

ITEM *lista_remover(LISTA *lista, int chave){
	NO *ant = NULL;	
	ITEM *temp;
	for(NO* aux = lista->ini; aux->prox != NULL; aux = aux->prox){
		if(item_get_chave(aux->info) == chave){
			if(aux == lista->ini)
				lista->ini = lista->ini->prox;
			else if(aux == lista->fim){
				lista->fim = ant;
				ant->prox = NULL;
			}else
				ant->prox = aux->prox;

			temp = aux->info;
			free(aux);
			return(temp);
		}
		ant = aux;
	}

	return NULL;
}

bool lista_inverter(LISTA **lista){
	NO* aux;

	if(lista != NULL && !lista_vazia(*lista)){
		NO *ant = NULL, *next = (*lista)->ini->prox;
		(*lista)->fim = (*lista)->ini;

		for(aux = (*lista)->ini; aux->prox != NULL; aux = next){
			next = aux->prox;
			(*lista)->ini = next;
			aux->prox = ant;
			ant = aux;
		}
		
		aux->prox = ant;
		(*lista)->ini = aux;

		return true;
	}else
		return false;
}