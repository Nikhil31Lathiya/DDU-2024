#include <stdio.h>
#include <stdlib.h>
// Structure of graph
typedef struct graph
{
    int **mat;
    int nodes, edges;
} graph;

// Structure of queue
typedef struct queue
{
    int *que;
    int front, rear;
} queue;

// Functions of the graph
int isempty(queue *q);
void enque(queue *q, int val);
int deque(queue *q);

// Functions of the graph
void create_graph(graph *g1);
void display(graph *g1);
void add_edge(graph *g1, int source, int destination);
void bfs(graph *g1);

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    printf("Enter number of nodes : ");
    scanf("%d", &g->nodes);
    create_graph(g);

    printf("Enter number of vertices : ");
    scanf("%d", &g->edges);

    for (int i = 0; i < g->edges; i++)
    {
        int s, d;
        printf("Enter source and destination : ");
        scanf("%d %d", &s, &d);
        add_edge(g, s, d);
    }

    display(g);

    printf("\n");
    bfs(g);
    return 0;
}

// CHecking if the queue is empty
int isempty(queue *q)
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

// Inserting elements into queue
void enque(queue *q, int val)
{
    if (isempty(q))
        q->front = 0;
    q->rear++;
    q->que[q->rear] = val;
}

// Removing elements from the queue
int deque(queue *q)
{
    int val = q->que[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

// Function to create adjacency matrix
void create_graph(graph *g1)
{
    printf("%d", g1->nodes);
    // // Dynamically allocating memory for 2d array
    g1->mat = (int **)malloc(g1->nodes * sizeof(int *));

    // Making columns of the matrix
    for (int i = 0; i < g1->nodes; i++)
    {
        g1->mat[i] = (int *)calloc(g1->nodes, sizeof(int));
    }
}

// Add Edges to the nodes
void add_edge(graph *g1, int source, int destination)
{
    source --;
    destination --;
    g1->mat[source][destination] = 1;
    g1->mat[destination][source] = 1;
}

// Function to display the adjacency matrix
void display(graph *g1)
{
    printf("\nMatrix :\n");
    for (int i = 0; i < g1->nodes; i++)
    {
        for (int j = 0; j < g1->nodes; j++)
        {
            printf("%d\t", g1->mat[i][j]);
        }
        printf("\n");
    }
}

// Function to perform breadth first search
void bfs(graph *g1)
{
    // Initializing queue
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = -1;
    q->que = (int *)calloc(g1->nodes, sizeof(int));

    
    // Array to keep track of status
    int *status = (int *)calloc(g1->nodes, sizeof(int));

    // Start with the first element
    enque(q, 0);
    status[0] = 1;

    int element;
    // While loop to perform bfs
    while (!isempty(q))
    {
        element = deque(q);
        for (int i = 0; i < g1->nodes; i++)
        {
            if (g1->mat[element][i] == 1 && status[i] == 0)
            {
                enque(q, i);
                status[i] = 1;
            }
        }
        status[element] = 2;
    }

    printf("\n");
    for (int i = 0; i < g1->nodes; i++)
    {
        printf("%d\t", status[i]);
    }
}


/*
0 -> Ready Stage
1 -> Waiting to be processed
2 -> Process Completed
*/