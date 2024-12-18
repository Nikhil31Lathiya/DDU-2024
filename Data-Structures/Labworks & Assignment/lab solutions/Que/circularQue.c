#include <stdio.h>
#include <stdlib.h>

struct c_que
{
    int front, rear;
    char *data;
    int size;
};

void enque(struct c_que *p, char val)
{
    if (p->front == -1 && p->rear == -1)
    {
        p->front += 1;
        p->rear += 1;
        p->data[p->rear] = val;
    }
    else if ((p->rear + 1) % p->size == p->front)
    {
        printf("\nQue is full\n");
    }
    else
    {
        p->rear = (p->rear + 1) % p->size;
        p->data[p->rear] = val;
    }
}

void deque(struct c_que *p)
{
    if (p->front == -1 && p->rear == -1)
    {
        printf("\nQue is empty\n");
    }
    else if (p->front == p->rear)
    {
        printf("\n| %c | is deleted \n", p->data[p->front]);
        p->front = p->rear = -1;
    }
    else
    {
        printf("\n| %c | is deleted \n", p->data[p->front]);
        p->front = (p->front + 1) % p->size;
        // p->front += 1;
    }
}

void display(struct c_que *p)
{
    int i = p->front;
    if (p->front == -1 && p->rear == -1)
    {
        printf("\nQue is Empty\n");
    }
    else
    {
        printf("\n\tQue is : -  ");
        // do
        // {
        //     printf("|%c| ->", p->data[i]);
        //     i = ((i + 1) % (p->size));
        // } while (i != p->rear);

        while (i != p->rear)
        {
            printf("|%c| ->", p->data[i]);
            i = (i + 1) % (p->size);
        }

        printf("|%c| ->", p->data[p->rear]);
    }
}

int main()
{
    struct c_que *p = malloc(sizeof(struct c_que));

    printf("Enter the size of an que : ");
    scanf("%d", &p->size);

    p->data = malloc(p->size * sizeof(char));

    p->front = -1;
    p->rear = -1;

    enque(p, 'h');
    enque(p, 'e');
    enque(p, 'l');
    enque(p, 'l');
    enque(p, 'o');

    display(p);

    deque(p);
    display(p);

    enque(p, 'z');
    display(p);

    return 0;
}