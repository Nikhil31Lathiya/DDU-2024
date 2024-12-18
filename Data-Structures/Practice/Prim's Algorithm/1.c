#include<stdio.h>
// defien maximum number of vertices
#define NODES 5
// define the highest number
#define INFINITY 999

// Function to find nodes with with minimum value and not yet present in minimum spanning tree
int minimum_weight(int weight[], int status[])
{
    int minimum = INFINITY;
    int min_node;

    // Iterate through all the nodes to find the minimum weight
    for(int i =0;i<NODES;i++)
    {
        // mst[i] == 0 indicate that the element has not been included in minimum spanning tree
        if (status[i]==0 && weight[i]<minimum)
        {
            // if weight of the vertice is less than the minimum then update the value of the minimum
            // New minimum becomes the weight of the ith element
            minimum = weight[i];
            
            // The minimum element becomes i;
            min_node = i;
        }
    }
    return min_node;
}

void prim(int g[NODES][NODES])
{
    // Array to store elements of the minimum spannig tree
    int tree[NODES];

    // Minimum weight of every node
    int weight[NODES];

    // Array to check if the node has been included in the mst or not
    int status[NODES];
    int edge;
    // Initializing weights of all nodes to infinity
    for(int i =0; i< NODES; i++)
    {
        weight[i] = INFINITY;
        
        // Status 0 indicate that the node has not been visited yet
        status[i] = 0;
    }

    // Selecting the root node to start tree
    weight[0] = 0; // Weight of the root node is 0
    tree[0] = -1; // indicate the root of the mst . -1 indicate that the root node has no parent


    int count; // To maintain count of nodes processed
    for(count = 0; count < NODES -1; count++)
    {
        edge = minimum_weight(weight,status);
        // Updating the status of the minimum edge as 1 to mark as visited
        status[edge] = 1;

        // Loop to check adjacent nodes of minimum node
        for(int j = 0; j<NODES;j++)
        {
            if(g[edge][j] && status[j]==0 && g[edge][j] < weight[j])
            {
                tree[j] = edge;
                weight[j] =g[edge][j];
            }
        }
    }

    printf("\nEdge\t Weight\n");
    for(int i = 1; i<NODES ;i++)
    {
        printf("%d <-> %d   %d\n",tree[i],i, weight[i]);
    }

}


int main()
{
     int g[NODES][NODES] = {{0, 0, 3, 0, 0},    
                                {0, 0, 10, 4, 0},    
                                {3, 10, 0, 2, 6},    
                                {0, 4, 2, 0, 1},    
                                {0, 0, 6, 1, 0},    
                                };   
    prim(g);
}