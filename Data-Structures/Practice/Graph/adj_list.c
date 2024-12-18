//  Graph using adjacency list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
} *new;

typedef struct node node;

// Create a new node in the list
void create_node()
{
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory Allocation Falied");
        return;
    }
    printf("\nEnter value for new node : ");
    scanf(" %c", &new->data);
    new->next = NULL;
}

// Function to create graph using adjacency list
void create_graph(node **a_list, int no_nodes)
{

    node *tail = NULL; // To store last element of the list
    
    int no_neigh;  // To get number of neighbours of that particular node;

    // Making edge for every every node of the graph
    for (int i = 0; i < no_nodes; i++)
    {
        tail = a_list[i];
        printf("\nEnter numbier of neighbours of  '%c' :",a_list[i][0].data);
        scanf("%d",&no_neigh);

        for(int j=0;j<no_neigh;j++)
        {
            printf("Enter Neighbour %d : ",j+1);
            create_node();
            tail->next = new;
            tail = tail->next;
        }
    }
}

// Fuction to create adjacency list
void display_graph(node **a_list, int no_nodes)
{
    node *temp;
    for(int i = 0;i<no_nodes;i++)
    {
        temp = a_list[i];
        while(temp!=NULL)
        {
            printf("%c -> ",temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    node **ad_list; // This will store the head pointers
    int n = 5;     // Number of nodes in the graph;

    ad_list = (node **)malloc(n * sizeof(node *)); // Create array of structure with n elements
    for(int i =0;i<n;i++)
    {
        // Making each head pointer
        ad_list[i] = (node *)malloc(sizeof(node));
    }


    // Creating all the head nodes
    for(int i =0;i<n;i++)
    {
        printf("\n\nNode : %d",i+1);
        create_node();
        ad_list[i] = new;
        new = NULL;
    }

    create_graph(ad_list,n);

    display_graph(ad_list,n);
}