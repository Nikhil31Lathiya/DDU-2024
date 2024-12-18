#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define a structure for the double-ended queue
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Deque;

// Function to initialize the double-ended queue
void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the double-ended queue is full
int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1));
}

// Function to check if the double-ended queue is empty
int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

// Function to add an element to the front of the double-ended queue (enQueueFront)
void enQueueFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot enqueue at front.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front--;
    }

    dq->items[dq->front] = value;
}

// Function to add an element to the rear of the double-ended queue (enQueueRear)
void enQueueRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot enqueue at rear.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->items[dq->rear] = value;
}

// Function to remove an element from the front of the double-ended queue (deQueueFront)
int deQueueFront(Deque *dq) {
    int item;
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot dequeue from front.\n");
        return -1;
    }

    item = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return item;
}

// Function to remove an element from the rear of the double-ended queue (deQueueRear)
int deQueueRear(Deque *dq) {
    int item;
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot dequeue from rear.\n");
        return -1;
    }

    item = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear--;
    }
    return item;
}

// Function to display the elements of the double-ended queue
void display(Deque *dq) {
    int i;
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Display Elements: ");
    i = dq->front;
    do {
        printf("%d ", dq->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (dq->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);
    int choice, value;

    while (1) {
        printf("-----------------------------\n");
        printf("1. enQueueFront\n");
        printf("2. enQueueRear\n");
        printf("3. deQueueFront\n");
        printf("4. deQueueRear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        // getchar();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enQueueFront: ");
                scanf("%d", &value);
                enQueueFront(&dq, value);
                display(&dq);
                break;
            case 2:
                printf("Enter value to enQueueRear: ");
                scanf("%d", &value);
                enQueueRear(&dq, value);
                display(&dq);
                break;
            case 3:
                printf("Dequeued element from front: %d\n", deQueueFront(&dq));
                display(&dq);
                break;
            case 4:
                printf("Dequeued element from rear: %d\n", deQueueRear(&dq));
                display(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
