#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *new, *head1, *head2, *tail1, *tail2, *new1;

typedef struct node node;

void create_node1(int d)
{
    new1 = (node *)malloc(1 * sizeof(node));
    if (new1 == NULL)
    {
        printf("Memory Allocation Falied.");
        return;
    }
    else
    {
        new1->next = NULL;
        new1->data = d;
    }
}

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

void l_union(node **head1, node **head2)
{
    node *temp1, *temp2, *nunion;
    nunion = *head1;
    temp2 = *head2;

    printf("\nUnion Result : \n");
    while (nunion->next != NULL)
    {
        printf("%d -> ", nunion->data);
        nunion = nunion->next;
    }
    printf("%d -> ", nunion->data);

    while (temp2 != NULL)
    {
        temp1 = *head1;
        int flag = 0; // Reset flag for each element in head2

        while (temp1 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                flag = 1;
                break;
            }
            temp1 = temp1->next;
        }

        if (flag == 0)
        {
            create_node1(temp2->data);
            nunion->next = new1;
            nunion = nunion->next;
            printf("%d -> ", nunion->data);
        }
        temp2 = temp2->next;
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

    l_union(&head1, &head2);

    return 0;
}