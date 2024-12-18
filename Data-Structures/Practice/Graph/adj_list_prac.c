#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

typedef struct node node;

void create_node(node **new_node)
{
    *new_node = (node *)malloc(sizeof(node));
    if (*new_node == NULL)
    {
        printf("Memory not allocated");
        return;
    }
    else
    {
        printf("\nEnter Value For New Node : ");
        scanf(" %c", &(*new_node)->data);
        (*new_node)->next = NULL;
    }
}

void create_graph(node **heads, int no_of_nodes)
{
    node *tail = NULL;
    int no_of_neighbour;

    for (int i = 0; i < no_of_nodes; i++)
    {
        tail = heads[i];
        printf("\nEnter Number Of Neighbours of %c : ", heads[i]->data);
        scanf("%d", &no_of_neighbour);

        printf("\n\n");
        for (int j = 0; j < no_of_neighbour; j++)
        {
            printf("Enter Neighbour : %d", j);
            node *new_neighbor;
            create_node(&new_neighbor);
            tail->next = new_neighbor;
            tail = tail->next;
        }
    }
}

void display_graph(node **head_list, int no_of_nodes)
{
    node *temp;
    for (int i = 0; i < no_of_nodes; i++)
    {
        temp = head_list[i];
        printf("\nHead -> ");
        while (temp != NULL)
        {
            printf(" %c ->", temp->data);
            temp = temp->next;
        }
        printf("Tail.");
    }
}

int main()
{
    node **head_list;
    int n = 5;

    head_list = (node **)malloc(n * sizeof(node *));
    if (head_list == NULL)
    {
        printf("Memory allocation failed");
        return 1; // Exit program with error
    }

    for (int i = 0; i < n; i++)
    {
        create_node(&(head_list[i]));
    }

    create_graph(head_list, n);

    display_graph(head_list, n);

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        node *current = head_list[i];
        while (current != NULL)
        {
            node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(head_list);

    return 0;
}
