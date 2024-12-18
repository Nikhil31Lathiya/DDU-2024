#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int isDirected;
    int isWeighted;
    int n;
    int m;
    int adjMatrix[MAX][MAX];
    int adjList[MAX][MAX];
} Graph;

Graph *createGraph(int isDirected, int isWeighted, int n, int m)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->isDirected = isDirected;
    graph->isWeighted = isWeighted;
    graph->n = n;
    graph->m = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph->adjMatrix[i][j] = 0;
            graph->adjList[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v, int w)
{
    if (graph->isDirected)
    {
        graph->adjMatrix[u][v] = w;
        graph->adjList[u][v] = w;
    }
    else
    {
        graph->adjMatrix[u][v] = graph->adjMatrix[v][u] = w;
        graph->adjList[u][v] = graph->adjList[v][u] = w;
    }
}

void dfs(Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < graph->n; i++)
    {
        if (graph->adjList[vertex][i] && !visited[i])
        {
            dfs(graph, i, visited);
        }
    }
}

void bfs(Graph *graph, int vertex)
{
    int queue[MAX], front = 0, rear = -1, visited[MAX] = {0};
    queue[++rear] = vertex;
    visited[vertex] = 1;
    while (front <= rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);
        for (int i = 0; i < graph->n; i++)
        {
            if (graph->adjList[vertex][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    FILE *file1 = fopen("tgraph.txt", "r");
    int isDirected1, isWeighted1, n1, m1;
    fscanf(file1, "%d %d\n%d %d", &isDirected1, &isWeighted1, &n1, &m1);
    Graph *graph1 = createGraph(isDirected1, isWeighted1, n1, m1);
    for (int i = 0; i < m1; i++)
    {
        int u, v, w = 1;
        if (isWeighted1)
        {
            fscanf(file1, "%d %d %d", &u, &v, &w);
        }
        else
        {
            fscanf(file1, "%d %d", &u, &v);
        }
        addEdge(graph1, u, v, w);
    }
    fclose(file1);

    FILE *file2 = fopen("fgraph.txt", "r");
    int isDirected2, isWeighted2, n2, m2;
    fscanf(file2, "%d %d\n%d %d", &isDirected2, &isWeighted2, &n2, &m2);
    Graph *graph2 = createGraph(isDirected2, isWeighted2, n2, m2);
    for (int i = 0; i < m2; i++)
    {
        int u, v, w = 1;
        if (isWeighted2)
        {
            fscanf(file2, "%d %d %d", &u, &v, &w);
        }
        else
        {
            fscanf(file2, "%d %d", &u, &v);
        }
        addEdge(graph2, u, v, w);
    }
    fclose(file2);

    printf("DFS traversal of tgraph.txt: ");
    int visited1[MAX] = {0};
    dfs(graph1, 0, visited1);
    printf("\nBFS traversal of tgraph.txt: ");
    bfs(graph1, 0);

    printf("\n\nDFS traversal of fgraph.txt: ");
    int visited2[MAX] = {0};
    dfs(graph2, 0, visited2);
    printf("\nBFS traversal of fgraph.txt: ");
    bfs(graph2, 0);

    return 0;
}
