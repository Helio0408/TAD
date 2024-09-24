#include "arvore.h"

struct no_{
	tipo info;
	int nvl;
	int altura;
	no* filho1;
	no* filho2;
}

struct arvore{
	no* ini;
	int nvl_max;
}

arvore* criar_arvore(){
	
}

//FAZER USANDO RECUSSAO

bool inserir_arvore(arvore* a, tipo x){

}

no* buscar_arvore(arvore* a, tipo x){

}

bool remover_arvore(arvore* a, no* n){

}

void destruir_arvore(arvore** a){

}