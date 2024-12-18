#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

} *front = NULL, *rear = NULL, *new = NULL, *tmp = NULL;

void create_node()
{
    new = malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("Memory is full");
    }
    else
    {
        new->next = NULL;
        printf("Enter the data to be inserted : ");
        scanf("%d", &new->data);
    }
}

void enque()
{
    create_node();

    if (front == NULL && rear == NULL)
    {
        front = new;
        rear = new;
    }
    rear->next = new;
    rear = new;
}

void deque()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nQue is Empty");
        return;
    }
    else
    {
        tmp = front;
        int val = tmp->data;

        front = tmp->next;
        printf("\n%d is deleted\n", val);
        free(tmp);
    }
}

void display()
{
    tmp = front;
    if (tmp == NULL)
    {
        printf("Link list is empty ");
    }
    else
    {
        while (tmp != NULL)
        {
            printf("%d ->", tmp->data);
            tmp = tmp->next;
        }
    }
}

int main()
{
    enque();
    enque();
    enque();
    display();

    deque();
    deque();
    deque();
    display();
    return 0;
}