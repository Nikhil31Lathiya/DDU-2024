#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
int count = 0;

node *create(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data= data;
    temp->next = NULL;
    count++;
    return temp;
}

void insert (node **head, int data)
{
    node *temp = create(data);
    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void delete_last(node **head)
{
    node *prev = NULL;
    node *current = *head;
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    count--;
}

void display(node *head)
{
    node *temp = head;
    while(temp !=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void priority_enqueue(node **head, int data)
{
    insert(head, data);
    node *temp1 = *head;
    node *temp2 = NULL;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                int h = temp1->data;
                temp1->data = temp2->data;
                temp2->data = h; 
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    printf("\n");
}

void priority_dequeue(node **head)
{
    delete_last(head);
}

int main()
{
    node *head = NULL;
    priority_enqueue(&head, 50);
    priority_enqueue(&head, 26);
    priority_enqueue(&head, 1);
    priority_enqueue(&head, 20);
    priority_dequeue(&head);
    display(head);
    return 0;
}