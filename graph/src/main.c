#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
	graph *g;
	//int **mat;

	g = Mygraph(10);
	add_edge(g, 1, 8, 5);
	add_edge(g, 4, 8, 3);

	adjacency_matrix(g);

	remove_min_edge(g);

	adjacency_matrix(g);
	
	remove_graph(g);
	return 0;
}