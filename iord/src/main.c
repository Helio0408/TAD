#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "lista.h"

int main(){
	int num, x, arr[100];
	lista *l;

	l = criar_lista();

	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		scanf("%d", &x);
		inserir_lista(l, criar_item(x));
		arr[i] = x;
	}

	imprimir_lista(l);

	remover_ord(l, arr);

	destruir_lista(&l);

	return 0;
}