#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "fila.h"

void cartas(int n);

void cartas(int n) {
	int cont = 0, descartadas[n-1];
	FILA *list = fila_criar();
	ITEM *aux;

	for(int i = 1; i <= n; i++)
		fila_inserir(list, item_criar(i));

	while(!fila_vazia(list)){
		aux = fila_remover(list);
		descartadas[cont++] = ((int)(item_get_chave(aux)));
		
		if(!fila_vazia(list)){
			aux = fila_remover(list);
			fila_inserir(list, item_criar(item_get_chave(aux)));
		}
	}
	if(n == 1){
		printf("Discarded cards: \n");
	}else{
		printf("Discarded cards: %d", descartadas[0]);
		for(int i = 1; i < n-1; i++)
			printf(", %d", descartadas[i]);

		printf("\n");
	}

	printf("Remaining card: %d\n", item_get_chave(aux));

	item_apagar(&aux);
	fila_apagar(&list);
}