#ifndef GRAPH_H
#define GRAPH_H
#define MAX_SIZE 10
typedef struct Graph
{
    int vertices;
    int edges;
    int adj_mat[MAX_SIZE][MAX_SIZE];
}graph;

void init_graph(graph *ptr_graph, int vertices, int edges);
void add_edge(graph *ptr_graph, int from, int to);
void dfs(graph *ptr_graph, int u);
void bfs(graph *ptr_graph, int u);
void display(graph *ptr_graph);
void deinit_graph(graph *ptr_graph);
#endif