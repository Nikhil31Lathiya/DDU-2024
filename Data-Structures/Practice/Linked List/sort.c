// Sort a linked list using insertion sort

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *new = NULL, *head = NULL, *tail = NULL;

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

void insert()
{
    create();
    if (head == NULL)
    {
        head = new;
    }
    // to insert small element at 1st
    else if(new->data<head->data)
    {
        new->next = head;
        head = new;
    }
    else
    {
        node *temp;
        temp = head;
        while ((temp->next != NULL) && (temp->next->data < new->data))
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    new = NULL;
}

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
    for (int i = 0; i < 5; i++)
    {
        insert();
    }
    display();
}