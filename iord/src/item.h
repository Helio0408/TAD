#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int elem;

typedef struct _item{
	elem valor;
} item;

item *criar_item(elem x);
bool set_valor(item *e, elem x);
elem get_valor(item *e);
void apagar_item(item **e);