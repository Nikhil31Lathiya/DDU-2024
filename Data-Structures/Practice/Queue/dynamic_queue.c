#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int *que;
    int capacity;
    int front, rear;
} queue;

// Dynamically Creating queue
queue *new_queue(int que_arr) // que_arr == capacity of the array of queue
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->que = (int *)malloc(que_arr * sizeof(int));
    if (q->que == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->capacity = que_arr;
    q->front = -1;
    q->rear = -1;
    return q;
}

int add(int a,int b)
{
    return a+b;
}

// Checking if the queue is empty or not
int isempty(queue *q)
{
    // if empty
    if (q->front < 0)
    {
        return 1;
    }
    // if not empty
    else
    {
        return 0;
    }
}

void dequeue(queue *q)
{
    if (isempty(q))
    {
        printf("Dequeue failed. Underflow");
    }
    else
    {
        printf("\n%d removed.\n", q->que[q->front]);
        q->front += 1;
    }
}

// Displaying all elements of the queue
void display(queue *q)
{
    printf("\n|");
    for (int i = 0; i <= q->rear; i++)
    {
        printf(" %d |", q->que[i]);
    }
    printf("\n");
}

// Enqueue operation
int enqueue(queue *q, int element)
{
    if (isempty(q))
    {
        q->front = 0;
    }
    q->rear += 1;
    if (q->rear == q->capacity)
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

int main()
{
    int que_no;
    printf("Enter number of queues : ");
    scanf("%d", &que_no);

    // Dynamically Requesting memory for number of queues inputed from user
    queue **q_n = (queue **)malloc(que_no * sizeof(queue *));
    int capacity;
    for (int i = 0; i < que_no; i++)
    {
        printf("Enter capacity of queue %d : ", i + 1);
        scanf("%d", &capacity);
        q_n[i] = new_queue(capacity);
    }

    int choise;

    while (1)
    {
        printf("\n1 -> Enqueue\n2 -> Dequeue\n3 -> Display All Queues\n4 -> Exit\n");
        scanf("%d", &choise);
        if (choise == 1)
        {
            int no_elmts, val;
            // Inputting elements for number of queues inputted by the user
            for (int i = 0; i < que_no; i++)
            {
                printf("Enter number of elements for queue : %d -> ", i + 1);
                // Taking total number of elements to be inserted into the queue
                scanf("%d", &no_elmts);

                if (no_elmts > q_n[i]->capacity)
                {
                    printf("Number Of Elements Greater Than Capacity. ERROR");
                }
                else
                {
                    // Inputting each element fron the user
                    for (int j = 0; j < no_elmts; j++)
                    {
                        printf("Element : %d -> ", j + 1);
                        scanf("%d", &val);

                        // Insertting each element into the queue
                        enqueue(q_n[i], val);
                    }
                }
            }
        }

        else if (choise == 2)
        {
            // Displaying all elements of each queue
            for (int i = 0; i < que_no; i++)
            {
                printf("\nQueue %d :", i + 1);
                dequeue(q_n[i]);
            }
        }

        else if (choise == 3)
        {
            // Displaying all elements of each queue
            for (int i = 0; i < que_no; i++)
            {
                printf("\nQueue %d :", i + 1);
                display(q_n[i]);
            }
        }

        else if (choise == 4)
        {
            break;
        }
    }

    return 0;
}