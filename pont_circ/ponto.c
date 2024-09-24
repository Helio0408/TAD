#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto_
{
    float x, y;
};
	
PONTO *ponto_criar(float x, float y){
    PONTO *p;

    p = (PONTO*)malloc(sizeof(PONTO));

    p->x = x;
    p->y = y;

    return p;
}

void ponto_apagar(PONTO *p){
    if(p != NULL)
        free(p);
}

bool ponto_set(PONTO *p, float x, float y){
    if(((*p).x == x) && ((*p).y == y))
        return true;
    else
        return false;
}

void ponto_get(PONTO *p, float *x, float *y){
    (*x) = (*p).x;
    (*y) = (*p).y;
}
