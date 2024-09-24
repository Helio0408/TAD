#include "item.h"

struct item_ {
	int valor;
};

ITEM *item_criar(int chave) {
	ITEM *p = (ITEM *)malloc(sizeof(ITEM));
	if(p != NULL) {
		p->valor = chave;
		return p;
	}
	return NULL;
}

bool item_set_chave(ITEM *item, int chave) {
	if(item != NULL) {
		item->valor = chave;
		return true;
	}
	return false;
}

int item_get_chave(ITEM *item) {
	if(item != NULL)
		return item->valor;
	
	exit(1); 
}

bool item_apagar(ITEM **item) {
	if(item != NULL) {
		free(*item);
		*item = NULL;
		return true;
	}

	return false;
}

void item_imprimir(ITEM *item){
	if(item != NULL)
		printf("[%d]; ", item_get_chave(item));
}