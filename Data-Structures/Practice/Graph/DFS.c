#include <stdio.h>
#include <stdlib.h>
// Structure of graph
typedef struct graph
{
    int **mat;
    int nodes, edges;
} graph;

// Structure of stack
typedef struct stack
{
    int *stk;
    int top;
    int size;
} stack;

// Functions of the stack
void push(stack *s1, int val);
int pop(stack *s1);
int isempty(stack *s1);
int isfull(stack *s1);

// Functions of the graph
void create_graph(graph *g1);
void display(graph *g1);
void add_edge(graph *g1, int source, int destination);
void dfs(graph *g1);

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
    dfs(g);
    printf("\n");
    return 0;
}

int isempty(stack *s1)
{
    if (s1->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(stack *s1)
{
    if (s1->top == s1->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *s1, int val)
{
    if (!isfull(s1))
    {

        s1->top++;
        s1->stk[s1->top] = val;
    }
}

int pop(stack *s1)
{
    if (!isempty(s1))
    {
        int val = s1->stk[s1->top];
        s1->top--;
        return val;
    }
}

// Function to create adjacency matrix
void create_graph(graph *g1)
{
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
    source--;
    destination--;
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
void dfs(graph *g1)
{
    // Creating stack
    stack *s = (stack *)malloc(1 * sizeof(stack));
    s->stk = (int *)calloc(g1->nodes, sizeof(int));
    s->size = g1->nodes;
    s->top = -1;
    // Array to store status of visited nodes
    int *status = (int *)calloc(g1->nodes, sizeof(int));
    int element;
    push(s, 0);
    status[0] = 1;
    while (!isempty(s))
    {
        element = pop(s);
        for (int i = 0; i < g1->nodes; i++)
        {
            if (g1->mat[element][i] == 1 && status[i] == 0)
            {
                push(s, i);
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