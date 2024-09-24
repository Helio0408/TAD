#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pilha.h"

int** alloc(int lin, int col);
void mem_free(int lin, int ***labr);
void scan_labr(int** labirinto, int lin, int col, pilha *p, int x, int y);

int** alloc(int lin, int col) {
	int **p = (int**) malloc(lin * sizeof(int*));
	assert(p != NULL);

	for(int i = 0; i < lin; i++){
		p[i] = (int*) malloc(col * sizeof(int));
		assert(p[i] != NULL);
	}

	return p;
}

void scan_labr(int** labirinto, int lin, int col, pilha *p, int x, int y) {
	if(y+1 < lin && labirinto[y+1][x] != 0)
		push(p, criar_item((y+1)*1000 + x));

	if(x-1 >= 0 && labirinto[y][x-1] != 0)
		push(p, criar_item((y)*1000 + x-1));
	
	if(y-1 >= 0 && labirinto[y-1][x] != 0)
		push(p, criar_item((y-1)*1000 + x));
	
	if(x+1 < col && labirinto[y][x+1] != 0)
		push(p, criar_item((y)*1000 + x+1));
}

void mem_free(int lin, int ***labr) {
	for(int i = 0; i < lin; i++)
		free((*labr)[i]);
	
	free(*labr);
}

int main(){

	int linha, coluna, **labirinto, x = 0, y = 0, topo, ant = -1, cont;
	pilha *p;
	item *aux;

	p = criar_pilha();

	scanf("%d %d", &linha, &coluna);
	labirinto = alloc(linha, coluna);

	for(int i = 0; i < linha; i++)
		for(int j = 0; j < coluna; j++)
			scanf("%d", &labirinto[i][j]);


	push(p, criar_item(0000));

	if(linha == 1 && coluna == 1)
		printf("(0, 0)\n");
	else{
		do {
			if(esta_vazia(p)){
				printf("Saída não encontrada.\n");
				break;
			}

			labirinto[y][x] = 0;

			pop(p, &aux);
			topo = get_valor(aux);
			destruir_item(aux);

			y = topo/1000;
			x = topo%1000;
			if(topo != ant)
				printf("(%d, %d)\n", y, x);

			ant = topo;

			scan_labr(labirinto, linha, coluna, p, x, y);
		}while(labirinto[y][x] != 2);
	}

	while(!esta_vazia(p)){
		pop(p, &aux);
		destruir_item(aux);
	}

	destruir_pilha(p);
	mem_free(linha, &labirinto);

	return 0;
}