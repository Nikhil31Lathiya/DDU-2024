#include <stdio.h>
#include <stdlib.h>

struct que
{
    int front, rear;
    int size;
    int *arr;
};

int is_full(struct que *q)
{
    if (q->rear >= q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_empty(struct que *q)
{
    if (q->rear == -1 && q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enque(struct que *q, int val)
{
    if (is_full(q))
    {
        printf("\nQue is full cant insert it any more \n");
        return;
    }
    else
    {
        if (is_empty(q))
        {
            q->rear += 1;
            q->front += 1;
            q->arr[q->rear] = val;
        }
        else
        {
            q->rear += 1;
            q->arr[q->rear] = val;
        }
    }
}

void display(struct que *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("| %d | -> ", q->arr[i]);
    }
}

void deque(struct que *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("\nQue is empty\n");
    }
    else
    {
        printf("\n %d is deleted \n", q->arr[q->front]);
        q->front += 1;
    }
}

int main()
{

    struct que *q = (struct que *)malloc(sizeof(struct que));

    printf("Enter the Size of an array : ");
    scanf("%d", &q->size);

    q->arr = (int *)malloc(q->size * sizeof(int));

    q->front = -1;
    q->rear = -1;

    enque(q, 5);
    enque(q, 15);
    enque(q, 52);
    enque(q, 53);
    enque(q, 51);
    display(q);

    // deque(q);
    // deque(q);

    // display(q);

    return 0;
}