#include "fila.h"
#include "cartas.c"

int main(int argc, char *argv[]){
   int n;

   while(scanf("%d", &n) && n != 0){
      cartas(n);
   }

   return 0;
}