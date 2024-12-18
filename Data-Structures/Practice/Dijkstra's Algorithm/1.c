// Implement Dijkstra's Algorithm
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999

// Structure of graph
typedef struct graph
{
    int **mat;
    int **weights;
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
void add_edge(graph *g1, int source, int destination, int weight);

// Function related to Dijkstra's Algorithm
void dijkstra_algorithm(graph *g1);
void print_path(int source, int destination, int parent[], int n, int total_nodes);

int main()
{
    // Making pointer of graph structure
    graph *g = (graph *)malloc(sizeof(graph));
    printf("Enter number of nodes : ");
    scanf("%d", &g->nodes);
    create_graph(g); // Function to create a graph

    // Forming Edges and vertices in the graph
    printf("Enter number of vertices : ");
    scanf("%d", &g->edges);
    // Establish the edges between nodes
    for (int i = 0; i < g->edges; i++)
    {
        int source, destination, weight;
        printf("Enter source and destination : ");
        scanf("%d %d", &source, &destination);
        printf("Enter Weight : ");
        scanf("%d", &weight);
        add_edge(g, source, destination, weight);
    }
    dijkstra_algorithm(g);
    return 0;
}

// Checking if the queue is empty
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
    // Making rows in 2d array to store weights
    g1->weights = (int **)malloc(g1->nodes * sizeof(int *));

    // Making columns of the matrix
    for (int i = 0; i < g1->nodes; i++)
    {
        g1->mat[i] = (int *)calloc(g1->nodes, sizeof(int));
        g1->weights[i] = (int *)calloc(g1->nodes, sizeof(int));
    }
}

// Add Edges to the nodes
void add_edge(graph *g1, int source, int destination, int weight)
{
    source--;
    destination--;
    g1->mat[source][destination] = 1;
    g1->mat[destination][source] = 1;
    g1->weights[source][destination] = g1->weights[destination][source] = weight;
}

void display1()
{
    printf("Hi");
}

// Function of dijkstra's algorithm
void dijkstra_algorithm(graph *g1)
{
    int *status, *parent_node, *node_distance_value;

    // Making variable of queue
    queue *q = (queue *)malloc(1 * sizeof(queue));
    q->que = (int *)malloc(g1->nodes * sizeof(int));
    q->front = -1;
    q->rear = -1;

    // Making array to store status of visited nodes
    status = (int *)calloc(g1->nodes, sizeof(int));

    // Making array to store parent-node of each node
    
    parent_node = (int *)calloc(g1->nodes, sizeof(int));

    // Array to store distance value of every node
    node_distance_value = (int *)malloc(g1->nodes * sizeof(int));
    node_distance_value[0] = 0;
    for (int i = 1; i < g1->nodes; i++)
    {
        // Making columns in each row of 2d array weights
        node_distance_value[i] = INFINITY;
    }

    // Start with the first element
    enque(q, 0);
    status[0] = 1;
    int element;

    // Loop For Traversal
    while (!isempty(q))
    {
        element = deque(q);
        for (int i = 0; i < g1->nodes; i++)
        {
            if (g1->mat[element][i] == 1 && status[i] == 0)
            {
                enque(q, i);
                node_distance_value[i] = node_distance_value[element] + g1->weights[element][i];
                parent_node[i] = element + 1;
                status[i] = 1;
            }
            else if (g1->mat[element][i] == 1 && status[i] == 1)
            {
                if (node_distance_value[i] > (node_distance_value[element] + g1->weights[element][i]))
                {
                    node_distance_value[i] = node_distance_value[element] + g1->weights[element][i];
                    parent_node[i] = element + 1;
                }
            }
        }
        status[element] = 2;
    }

    // Print Details like => node name, distance. parent-node
    for (int i = 0; i < g1->nodes; i++)
    {
        printf("Node : %d\t => Distance : %d\t => Parent Node : %d\n", i + 1, node_distance_value[i], parent_node[i]);
    }
    int s = 1, d;
    int total_nodes = g1->nodes;
    int n = 0;
    printf("Enter destination : ");
    scanf("%d", &d);
    print_path(s, d, parent_node, n, total_nodes);
}

void print_path(int source, int destination, int parent[], int n, int total_nodes)
{
    if (source == destination)
    {
        printf("%d", destination);
        return;
    }
    printf("%d -> ", source);
    for (int i = n; i < total_nodes; i++)
    {
        if (parent[i] == source)
        {
            source = i+1;
            n++;
            print_path(source, destination, parent, n, total_nodes);
            return;
        }
    }
}