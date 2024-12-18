#include <stdio.h>
#include <stdlib.h>
#define MAX 99

struct graph
{
    int Total_edge;
    int size;
    int **mat;
    int **weight_mat;
};

void create_graph(struct graph *g)
{
    printf("%d", g->size);

    g->mat = malloc(g->size * sizeof(int *));
    g->weight_mat = (int **)malloc(g->size * sizeof(int *));

    for (int i = 0; i < g->size; i++)
    {
        g->mat[i] = calloc(g->size, sizeof(int));
        g->weight_mat[i] = (int *)calloc(g->size, sizeof(int));
    }
    for (int i = 0; i < g->size; i++)
    {
        for (int j = 0; j < g->size; j++)
        {
            g->weight_mat[i][j] = MAX;
        }
    }
}

void add_edge(struct graph *g, int s, int d)
{
    s--;
    d--;
    g->mat[s][d] = 1;
    g->mat[d][s] = 1;
}
void add_weight(struct graph *g, int s, int d, int w)
{
    s--;
    d--;
    g->weight_mat[s][d] = w;
}
void display(struct graph *g)
{
    for (int i = 0; i < g->size; i++)
    {
        for (int j = 0; j < g->size; j++)
        {
            printf("%d ", g->mat[i][j]);
        }
        printf("\n");
    }
}
void display_weight(struct graph *g)
{
    for (int i = 0; i < g->size; i++)
    {
        for (int j = 0; j < g->size; j++)
        {
            printf("%d \t", g->weight_mat[i][j]);
        }
        printf("\n");
    }
}

struct que
{
    int front;
    int rear;
    int *arr;
};

int isempty(struct que *q)
{
    if (q->front == -1)
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
    if (isempty(q))
    {
        q->front += 1;
    }
    q->rear += 1;
    q->arr[q->rear] = val;
}

int deque(struct que *q)
{
    int val = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front += 1;
    }
    return val;
}

void bfs(struct graph *g);
int main()
{
    struct graph *g = malloc(sizeof(struct graph));

    printf("Enter the total number of nodes (size of grapgh) : ");
    scanf("%d", &g->size);

    create_graph(g);

    printf("Enter the number of Edges/ vertices : ");
    scanf("%d", &g->Total_edge);

    for (int i = 0; i < g->Total_edge; i++)
    {
        int s, d;
        printf("Enter the source and destination : ");
        scanf("%d %d", &s, &d);

        add_edge(g, s, d);
    }

    display(g);

    printf("\n");
    bfs(g);

    return 0;
}

void bfs(struct graph *g)
{
    struct que *q = malloc( sizeof(struct que));
    q->front = q->rear = -1;

    q->arr = calloc(g->size, sizeof(int)); // que

    int *status = calloc(g->size, sizeof(int)); // visited status array
    enque(q, 0);
    status[0] = 1;
    int element;

    while (!isempty(q))
    {
        element = deque(q);

        for (int i = 0; i < g->size; i++)
        {
            if (g->mat[element][i] == 1 && status[i] == 0)
            {
                enque(q, i);
                status[i] = 1;
            }
        }
        status[element] = 2;
    }

    for (int i = 0; i < g->size; i++)
    {
        printf("%d\t", status[i]);
    }
}
