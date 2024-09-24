#include "graph.h"

typedef struct graph_{
	int** vertex;
	int vertex_num;
}graph;

graph *Mygraph(int n){
	graph *g;
	int** v;

	g = (graph*)malloc(sizeof(graph));
	assert(g != NULL);

	v = (int**)malloc(n*sizeof(int*));	

	for(int i = 0; i < n; i++){
		v[i] = (int*)malloc(n*sizeof(int));
		assert(v[i] != NULL);

		for(int j = 0; j < n; j++)
			v[i][j] = 0;
	}

	g->vertex = v;
	g->vertex_num = n;

	return g;
}

bool exist_edge(graph *g, int x, int y){
	if(g->vertex[x][y] != 0)
		return true;
	else
		return false;
}

int *get_adj_vertex(graph *g, int x){
	int *l, aux[number_of_vertexs(g)], cont = -1;
	
	for(int i = 0; i < number_of_vertexs(g); i++)
		if(g->vertex[x][i] != 0){
			cont++;
			aux[cont] = i;
		}

	l = (int*)malloc(cont*sizeof(int));

	for(int i = 0; i < cont; i++)
		l[i] = aux[i];

	return l;
}

void remove_edge(graph *g, int x, int y){
	if(g->vertex[x][y] != 0){
		g->vertex[x][y] = 0;
		g->vertex[y][x] = 0;
	}
}

/*
void print_info(graph *g){

}
*/

int number_of_vertexs(graph *g){
	return g->vertex_num;
}

void remove_graph(graph *g){
	for(int i = 0; i < number_of_vertexs(g); i++)
		free(g->vertex[i]);

	free(g->vertex);
	free(g);
}

void add_edge(graph *g, int x, int y, int peso){
	for(int i = 0; i < number_of_vertexs(g); i++){
		g->vertex[x][y] = peso;
		g->vertex[y][x] = peso;
	}
}

void remove_min_edge(graph *g){
	int min_p = 0, x_min, y_min;

	for(int i = 0; i < number_of_vertexs(g); i++)
		for(int j = 0; j < number_of_vertexs(g); j++)
			if(g->vertex[i][j] > min_p){
				x_min = i;
				y_min = j;
			}

	remove_edge(g, x_min, y_min);
}

void adjacency_matrix(graph *g){
	printf("* ");

	for(int i = 0; i < number_of_vertexs(g); i++)
		printf("%d ", i);
	printf("\n");

	for(int i = 0; i < number_of_vertexs(g); i++){
		printf("%d ", i);

		for(int j = 0; j < number_of_vertexs(g); j++)
			printf("%d ", g->vertex[i][j]);

		printf("\n");
	}
	
	printf("\n");
}