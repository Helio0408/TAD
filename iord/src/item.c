#include "item.h"

item *criar_item(elem x){
	item *p = (item*)malloc(sizeof(item));
	if(p != NULL){
		p->valor = x;
		return p;
	}

	return NULL;
}

bool set_valor(item *e, elem x){
	if(e != NULL){
		e->valor = x;
		return true;
	}

	return false;
}

elem get_valor(item *e){
	assert(e != NULL);
		
	return e->valor;
}

void apagar_item(item **e){
	if(e != NULL){
		free(*e);
		*e = NULL;
	}
}