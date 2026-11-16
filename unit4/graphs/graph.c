#include <stdio.h>
#include "graph.h"
#include "queue_list.h"

void init_graph(graph *ptr_graph, int vertices, int edges)
{
    ptr_graph->edges=edges;
    ptr_graph->vertices=vertices;
    for(int i=0;i<MAX_SIZE;i++)
    {
        for(int j=0;j<MAX_SIZE;j++)
        {
            ptr_graph->adj_mat[i][j]=0;
        }
    }
}

void add_edge(graph *ptr_graph, int from, int to)
{
    ptr_graph->adj_mat[from][to]=1;
    ptr_graph->adj_mat[to][from]=1;
}

static void dfs_recursive(int n, int a[n][MAX_SIZE], int visited[], int u)
{
    visited[u]=1;
    printf("Visited %c \n",u + 'A');
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && a[u][i])
        {
            dfs_recursive(n,a,visited,i);
        }
    }
}

void dfs(graph *ptr_graph, int u)
{
    int visited[MAX_SIZE]; // int visited[ptr_graph->vertices] can also be done logically, but its safer to use max size
    for(int i=0;i<ptr_graph->vertices; i++)
    {
        visited[i]=0;
    }
    dfs_recursive(ptr_graph->vertices, ptr_graph->adj_mat, visited, u);
    printf("\n");
}

void bfs(graph *ptr_graph, int u)
{
    int n = ptr_graph->vertices;
    queue q;
    init_queue(&q);
    int visited[MAX_SIZE];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int v;
    visited[u] = 1; //marking the 1st node as visited
    enqueue(&q,u);
    while(!is_empty(&q))
    {
        v = dequeue(&q);
        printf("visiting: %c\n",v + 'A');

        for(int i=0;i<n;i++)
        {
            if(!visited[i] && ptr_graph->adj_mat[v][i])
            {
                enqueue(&q, i);
                visited[i]=1;
            }
        }
    }
    deinit_queue(&q);
}

void display(graph *ptr_graph)
{
    for(int i=0;i<ptr_graph->vertices;i++)
    {
        for(int j=0; j<ptr_graph->vertices; j++)
        {
            printf("%d ",ptr_graph->adj_mat[i][j]); 
        }
        printf("\n");
    }
}

void deinit_graph(graph *ptr_graph)
{
    ptr_graph->vertices = 0;
    ptr_graph->edges= 0;
}
