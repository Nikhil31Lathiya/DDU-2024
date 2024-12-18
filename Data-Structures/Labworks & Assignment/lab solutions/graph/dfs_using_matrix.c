#include <stdio.h>
#include <stdlib.h>

struct graph
{
    int total_edges;
    int **mat;
    int size;
};

void create(struct graph *g)
{
    g->mat = (int **)malloc(g->size * sizeof(int *));

    for (int i = 1; i <= g->size; i++)
    {
        g->mat[i] = (int *)calloc(g->size, sizeof(int));
    }
}

void add_edge(struct graph *g, int s, int d)
{
    g->mat[s][d] = 1;
    g->mat[d][s] = 1;
}

void display(struct graph *g)
{
    for (int i = 1; i <= g->size; i++)
    {
        for (int j = 1; j <= g->size; j++)
        {
            printf("%d ", g->mat[i][j]);
        }
        printf("\n");
    }
}

void dfs(struct graph *g)
{
    
}
int main()
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    printf("Enter the total number of nodes : ");
    scanf("%d", &g->size);

    create(g);

    printf("Enter the total no of edges : ");
    scanf("%d", &g->total_edges);

    for (int i = 1; i <= g->total_edges; i++)
    {
        int s, d;
        printf("Enter the source and destination : ");
        scanf("%d %d", &s, &d);

        add_edge(g, s, d);
    }

    display(g);

    return 0;
}