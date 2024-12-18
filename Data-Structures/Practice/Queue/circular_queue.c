#include <stdio.h>
#include <stdlib.h>
typedef struct que
{
    int *arr; // arr[5]
    int front;
    int rear;
    int size;
} queue;

int is_full(queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_empty(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(queue *q, int val)
{
    if (is_full(q))
    {
        printf("Queue Overflow");
        return;
    }
    else
    {
        if (is_empty(q))
        {
            q->front += 1;
        }
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

void deque(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue Underflow");
        return;
    }
    else
    {
        int val = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front += 1;
        }
        printf("\n%d removed.\n", val);
    }
}

void display(queue *q)
{
    if (q->rear >= q->front)
    {
        printf("\n----------Queue----------\n");
        printf("|");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf(" %d |", q->arr[i]);
        }
    }
    else
    {
        printf("\n----------Queue----------\n");
        printf("|");
        for (int i = 0; i <= q->rear; i++)
        {
            printf(" %d |", q->arr[i]);
        }
        for (int i = q->front; i < q->size; i++)
        {
            printf(" %d |", q->arr[i]);
        }
    }
}

int main()
{
    queue *que = (queue *)malloc(sizeof(queue));
    que->arr = (int *)malloc(5 * sizeof(int));
    que->front = -1;
    que->rear = -1;
    que->size = 5;
    enque(que, 1);
    enque(que, 2);
    enque(que, 3);
    enque(que, 4);
    enque(que, 5);

    display(que);
    printf("\n");
    deque(que);
    display(que);
    printf("\n");
    enque(que, 6);
    display(que);
    enque(que, 7);
    display(que);
    return 0;
}