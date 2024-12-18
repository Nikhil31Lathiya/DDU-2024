#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.c"

struct que
{
    int front;
    int rear;
    int *que_arr;
};

int is_empty(struct que *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(struct que *q, int val)
{
    if (is_empty(q))
    {
        q->front += 1;
    }
    q->rear += 1;
    q->que_arr[q->rear] = val;
}

int deque(struct que *q)
{
    if (is_empty(q))
    {
        printf("Cant deque the que is empty : ");
        return 0;
    }
    else if (q->front == q->rear)
    {
        int ele = q->front;
        q->front = -1;
        q->rear = -1;

        return ele;
    }
    else
    {
        int ele = q->front;

        q->front += 1;
        return ele;
    }
}

void bfs(struct graph *g)
{
    struct que *q = malloc(sizeof(struct que));

    q->front = q->rear = -1;

    q->que_arr = malloc(g->size * sizeof(int));
    int *visited = calloc(g->size, sizeof(int));

    int start, element;

    printf("Enter ther starting node : ");
    scanf("%d", &start);

    enque(q, start);
    visited[start] = 1;

    while (!is_empty(q))
    {
        element = deque(q);

        for (int i = 1; i <= g->size; i++)
        {
            if (g->mat[element][i] == 1 && visited[i] == 0)
            {
                enque(q, i);
                visited[i] = 1;
            }
        }
        visited[element] = 2;
    }

    for (int i = 1; i <= g->size; i++)
    {
        printf("%d\t", visited[i]);
    }
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

    bfs(g);
    return 0;
}