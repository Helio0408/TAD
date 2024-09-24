#include "lista.h"

lista *criar_lista() {
	item *term = (item*)malloc(TAM_MAX*sizeof(item));
	assert(term != NULL);

	for(int i = 0; i < TAM_MAX; i++)
		set_valor(&(term[i]), -1);

	lista *l = (lista*)malloc(sizeof(lista));

	l->ini = term;
	l->fim = NULL;
	l->tam = 0;

	return l;
}

bool esta_vazia(lista *l) {
	assert(l != NULL);
	
	if(l->tam == 0)
		return true;
	else
		return false;
}

bool esta_cheia(lista *l) {
	assert(l != NULL);

	if(l->tam == TAM_MAX)
		return true;
	else
		return false;
}

int tamanho_lista(lista *l) {
	assert(l != NULL);

	return l->tam;
}

void destruir_lista(lista **l) {
	free((*l)->ini);
	free(*l);

	*l = NULL;
}

item *busca_lista(lista *l, item *x) {
	item *aux = l->ini;

	while(aux != NULL && get_valor(aux) != get_valor(x))
		aux++;

	if(aux == NULL)
		return NULL;

	if(get_valor(aux) == get_valor(x))
		return aux;

	return NULL;
}

bool inserir_lista(lista *l, item *x) {
	assert(l != NULL);
	int j, k = 1, t1;
	item val;

	t1 = l->tam;
	set_valor(&((l->ini)[l->tam]),get_valor(x));
	l->tam++;

	if(esta_vazia(l))
		l->fim = l->ini;
	else
		l->fim++;

	while(k < l->tam)
		k = 3*k + 1;

	while(k > 0) {
		for(int i = k; i < l->tam; i++) {
			val = (l->ini)[i];
			j = i;

			while(j > k - 1 && get_valor(&val) <= get_valor(&((l->ini)[j - k]))) {
				(l->ini)[j] = (l->ini)[j - k];
				j = j - k;
			}
			(l->ini)[j] = val;
		}
		k = k/3;
		}

	if(t1 == l->tam)
		return false;
	else
		return true;
}

bool remover_lista(lista *l, item *x) {
	assert(l != NULL);

	for (int i = 0; i < l->tam; i++)
		if (get_valor(&(l->ini[i])) == get_valor(x)) {
			for (int j = i; j < l->tam - 1; j++) {
				l->ini[j] = l->ini[j + 1];
			}

			l->tam--;

			return true;
		}

	return false;
}

void imprimir_lista(lista *l) {
	assert(l !=  NULL);
	for(int i = 0; get_valor(&((l->ini)[i])) != -1; i++)
		printf("[%d]; ", get_valor(&(l->ini)[i]));

	printf("\n\n");
}

void remover_ord(lista *l, int arr[]){
	for(int i = 0; i < l->tam; i++)
		remover_lista(l, criar_item(arr[i]));
}