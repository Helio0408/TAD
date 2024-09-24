#include <stdio.h>
#include "circulo.h"

int main(){
    PONTO *p, *pc;
    CIRCULO *r;
    float dist;
    float x, y, raio;
    
    scanf("%f %f", &x, &y);

    p = ponto_criar(x, y);

    scanf("%f %f %f", &x, &y, &raio);

    pc = ponto_criar(x, y);
    r = circulo_criar(pc, raio);

    dist = distancia(p, r);

    if(dist < raio)
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    else if(dist > raio)
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    else
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);

    ponto_apagar(p);
    circulo_apagar(r);
    ponto_apagar(pc);
   
    return 0;
}