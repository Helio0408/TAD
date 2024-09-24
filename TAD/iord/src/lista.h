#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "item.h"

#define TAM_MAX 100

typedef struct lista_ {
	item *ini, *fim;
	int tam;
} lista;

lista *criar_lista();
bool esta_vazia(lista *l);
bool esta_cheia(lista *l);
int tamanho_lista(lista *l);
void destruir_lista(lista **l);
item *busca_lista(lista *l, item *x);
bool inserir_lista(lista *l, item *x);
bool remover_lista(lista *l, item *x);
void imprimir_lista(lista *l);

void remover_ord(lista *l, int arr[]);
