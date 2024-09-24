#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int num, term;
	LISTA *l;

	l = lista_criar();

	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		scanf("%d", &term);
		lista_inserir(l, item_criar(term));
	}

	lista_inverter(&l);

	lista_imprimir(l);

	lista_apagar(&l);

	return 0;
}