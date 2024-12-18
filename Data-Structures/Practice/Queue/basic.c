#include <stdio.h>
#define MAX 10
typedef struct queue
{
    int que[MAX];
    int front, rear;
} queue;


int isempty(queue *q)
{
    if (q->front < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Inserting elements into queue
int enqueue(queue *q, int element)
{
    if (isempty(q))
    {
        q->front = 0;
    }
    q->rear += 1;
    if (q->rear == MAX)
    {
        q->rear -= 1;
        printf("Queue Underflow");
        return 0;
    }
    else
    {
        if (q->que[q->rear] = element)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


// Display All elements of the queue
void display(queue *q)
{
    printf("\n\n|");
    for (int i = 0; i <= q->rear; i++)
    {
        printf(" %d |", q->que[i]);
    }
}

int main()
{
    queue q;
    q.front = -1;
    q.rear = -1;

    // Inputting Values For Queue
    int val;
    printf("Enter Queue Values : \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Next : ");
        scanf("%d", &val);
        if (enqueue(&q, val))
        {
            printf("Enqueue Successfull -> %d\n", val);
        }
        else
        {
            printf("Enqueue Unsuccessfull -> %d\n", val);
        }
    }

    display(&q);
}