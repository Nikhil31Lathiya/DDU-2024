#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *new = NULL, *tail = NULL;

typedef struct node list;

void create()
{
    new = (list *)malloc(sizeof(list));
    if (new == NULL)
    {
        printf("Unsuccessfull Memory ALlocation.");
        return;
    }

    new->prev = new->next = NULL;
    printf("Enter Value For Node : ");
    scanf("%d", &new->data);
}

int is_empty()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert_at_first()
{
    create();
    if (is_empty())
    {
        head = new;
        tail = new;
    }
    else
    {
        new->next = head;
        head->prev = new;
        head = new;
    }
    new = NULL;
    return;
}

void insert_at_end()
{
    if (tail == NULL)
    {
        insert_at_first();
        return;
    }
    else
    {
        create();
        tail->next = new;
        new->prev = tail;
        tail = new;
    }
    new = NULL;
    return;
}

void display()
{
    printf("==========Linked List==========\n");
    list *temp = head;
    while (temp != NULL)
    {
        printf("| %d |->", temp->data);
        temp = temp->next;
    }
    temp = NULL;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        insert_at_first();
    }
    for (int i = 0; i < 4; i++)
    {
        insert_at_end();
    }
    display();
    return 0;
}
