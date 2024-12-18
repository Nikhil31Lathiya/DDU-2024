#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *new, *head1, *head2, *tail1, *tail2;

typedef struct node node;

void create_node()
{
    new = (node *)malloc(1 * sizeof(node));
    if (new == NULL)
    {
        printf("Memory Allocation Falied.");
        return;
    }
    else
    {
        new->next = NULL;
        printf("Enter data for the node : ");
        scanf("%d", &new->data);
    }
}

void insert_last(node **head, node **tail)
{
    create_node();
    if (*tail == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
        new = NULL;
    }
}

void display(node *head)
{
    printf("\nHead -> ");
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Tail\n");
}

void merge(node **h1, node **h2)
{
    node *temp_t1 = *h1; // Traversal for list 1
    node *temp_t2 = *h2; // Traversal for list 2
    node *temp_1, *temp_2; // Temporary nodes for swapping

    while (temp_t1 != NULL && temp_t2 != NULL)
    {
        temp_1 = temp_t1->next;
        temp_2 = temp_t2->next;

        temp_t1->next = temp_t2;
        temp_t2->next = temp_1;
        
        temp_t1 = temp_1; // Move to the next node in list 1
        temp_t2 = temp_2; // Move to the next node in list 2
    }
}

int main()
{
    int no_l1, no_l2;
    printf("\nEnter number of nodes in list 1 : ");
    scanf("%d", &no_l1);
    for (int i = 0; i < no_l1; i++)
    {
        printf("\nElement : %d ", i + 1);
        insert_last(&head1, &tail1);
    }

    printf("\nEnter number of nodes in list 2 : ");
    scanf("%d", &no_l2);
    for (int i = 0; i < no_l1; i++)
    {

        printf("\nElement : %d ", i + 1);
        insert_last(&head2, &tail2);
    }

    printf("List 1 Elements : ");
    display(head1);

    printf("\nList 2 Elements : ");
    display(head2);

    merge(&head1, &head2);
    printf("\nAfter Merge : \n");
    display(head1);
    return 0;
}