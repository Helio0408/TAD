all: item.o pilha.o main.o
	gcc -g item.o pilha.o main.o -o dfs -std=c99 -Wall

item.o:
	gcc -g -c item.c -o item.o

pilha.o:
	gcc -g -c pilha.c -o pilha.o
	 
main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o dfs

run:
	./dfs