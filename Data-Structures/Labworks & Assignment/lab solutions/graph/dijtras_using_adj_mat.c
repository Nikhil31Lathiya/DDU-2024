#include <stdio.h>
#include "bfs.c"
#define MAX 99

void dijtras(struct graph *g)
{
    int s;
    int *dist = malloc(g->size * sizeof(int));

    for (int i = 1; i <= g->size; i++)
    {
        dist[i] = MAX;
    }

    printf("Enter the source : ");
    scanf("%d", &s);

    dist[s] = 0;

    for (int i = 1; i <= g->size; i++)
    {
        // int min = findMin(dist,)
    }
}

int main()
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    printf("Enter the total number of nodes : ");
    scanf("%d", &g->size);

    create(g);

    printf("Enter the total no of edges : ");
    scanf("%d", &g->Total_edge);

    for (int i = 1; i <= g->Total_edge; i++)
    {
        int s, d, w;
        printf("Enter the source and destination : ");
        scanf("%d %d", &s, &d);

        add_edge(g, s, d);

        printf("Enter the weight : ");
        scanf("%d", &w);
        add_weight(g, s, d, w);
    }

    printf("\nyour Adjency matrix : \n\n");
    display(g);

    printf("\n\n your weight matrix : \n\n");
    display_weight(g);
    
    bfs(g);

    dijtras(g);
    return 0;
}