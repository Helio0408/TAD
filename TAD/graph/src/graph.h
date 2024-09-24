#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct graph_ graph;

graph *Mygraph(int n);
bool exist_edge(graph *g, int x, int y);
int *get_adj_vertex(graph *g, int x);
void remove_edge(graph *g, int x, int y);
void print_info(graph *g);
int number_of_vertexs(graph *g);
void remove_graph(graph *g);
void add_edge(graph *g, int x, int y, int peso);
void remove_min_edge(graph *g);
void adjacency_matrix(graph *g);
