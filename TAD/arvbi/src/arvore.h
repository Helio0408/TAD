#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <asserts.h>

typedef int tipo;
typedef struct no_ no;
typedef struct arvore_ arvore;

arvore* criar_arvore();
bool inserir_arvore(arvore* a, tipo x);
no* buscar_arvore(arvore* a, tipo x);
bool remover_arvore(arvore* a, no* n);
void destruir_arvore(arvore** a);
