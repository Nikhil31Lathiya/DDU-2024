// Swap Head and tail node of the list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *new, *head, *tail;

typedef struct node node;

void create()
{
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory Allocation Failed.");
        return;
    }
    else
    {
        new->next = NULL;
    }
    printf("Enter Value : ");
    scanf("%d", &new->data);
}

void insert_at_front()
{
    create();
    if (head == NULL)
    {
        head = new;
        tail = new;
        new = NULL;
        return;
    }
    else
    {
        new->next = head;
        head = new;
        new = NULL;
        return;
    }
}

void insert_at_end()
{
    if (tail == NULL)
    {
        insert_at_front();
        return;
    }
    else
    {
        create();
        tail->next = new;
        tail = new;
        new = NULL;
        return;
    }
}

void swap()
{
    node *temp_head;
    // node *temp_tail = tail;
    node *temp1;
    temp1 = head;
    while (temp1->next != tail)
    {
        temp1 = temp1->next;
    }
    temp1->next = head;
    tail->next = head->next;
    temp_head = head;
    head = tail;
    tail = temp_head;
    tail->next = NULL;

}

// void display list
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements : \n");
        temp = head;
        int i = 1;
        while (temp != NULL)
        {
            printf("Node : %d\t", i);
            printf("Value : %d\n", temp->data);
            temp = temp->next; // when last node is reached temp will automatically be initiated with null
            i++;
        }
        printf("\n");
    }
}

int main()
{
    insert_at_front();
    for (int i = 0; i < 4; i++)
    {
        insert_at_end();
    }
    display();

    swap();
    printf("After swap : \n");
    display();
    return 0;
}