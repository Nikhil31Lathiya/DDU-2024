// Implementing Queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *new = NULL, *front = NULL, *rear = NULL;

typedef struct node queue;

int is_empty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void create()
{
    new = (queue *)malloc(sizeof(queue));
    if (new == NULL)
    {
        printf("Failed To Insert New Element");
    }
    new->next = NULL;
}

void display()
{
    queue *temp = front;
    printf("|");
    while (temp != NULL)
    {
        printf(" %d |", temp->data);
        temp = temp->next;
    }
    free(temp);
}

void enqueue()
{
    create();
    printf("Enter New Queue Element : ");
    scanf("%d", &new->data);
    if (is_empty())
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
    new = NULL;
}

void dequeue()
{
    queue *temp;
    if (is_empty())
    {
        printf("List Empty.\n");
        return;
    }
    else
    {
        if (front == rear)
        {
            front = rear = NULL;
            return;
        }
        else
        {
            temp = front;
            front = front->next;
            free(temp);
        }
    }
}

int main()
{
    int choise;
    while (1)
    {
        printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Display\n");
        scanf("%d", &choise);
        if (choise == 1)
        {
            enqueue();
            printf("Updated Queue:\n");
            display();
            printf("\n");
        }
        else if (choise == 2)
        {
            dequeue();
            printf("Updated Queue:\n");
            display();
            printf("\n");
        }
        else if (choise == 3)
        {
            printf("Queue:\n");
            display();
            printf("\n");
        }
        else
        {
            break;
        }
    }
    return 0;
}