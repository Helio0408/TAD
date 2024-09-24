#include <stdio.h>
#include <stdbool.h>

bool balanceada(char *sequencia);

bool balanceada(char *sequencia) {
    int tam = 0;

    while (sequencia[tam] != '\0') {
        tam++;
    }

    if (tam % 2 != 0) {
        return false;
    }

    char pilha[1001];
    int top = -1;

    for (int i = 0; i < tam; i++) {
        if (sequencia[i] == '(' || sequencia[i] == '[' 
		|| sequencia[i] == '{') {

            pilha[++top] = sequencia[i];

        } else {
            if (top == -1) {
                return false;
            }
            char abr = pilha[top--];
            if ((abr == '(' && sequencia[i] != ')') 
			|| (abr == '[' && sequencia[i] != ']') 
			|| (abr == '{' && sequencia[i] != '}')) {
				
                return false;

            }
        }
    }

    return (top == -1);
}