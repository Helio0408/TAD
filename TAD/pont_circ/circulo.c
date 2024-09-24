#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"

struct circulo_
{
    PONTO *ponto;
    float raio;
};


CIRCULO *circulo_criar(PONTO *p, float raio){
    CIRCULO *circ;

    circ = (CIRCULO*)malloc(sizeof(CIRCULO));

    (*circ).ponto = p;
    (*circ).raio = raio;

    return circ;
}    

void circulo_apagar (CIRCULO *circ){
    free(circ);
}

float circulo_area (CIRCULO *circ){
    float area;
    area = (3,1415*pow((*circ).raio, 2));

    return area;
}

//Criado nesse arquivo .c para pois nele já temos o ponto.h incluso e
//para manter a definição da função fora do alcance do usuário
float distancia(PONTO *p, CIRCULO *r){
    float x1, x2, y1, y2, distancia;

    ponto_get(p, &x1, &y1);
    ponto_get((r->ponto), &x2, &y2);

    distancia = sqrt(pow((x2 - x1),2) + pow((y2 - y1), 2));

    return distancia;
}