#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct deque
{
    int arr[MAX];
    int left, right;
} deque;

int is_empty(deque *d)
{
    if (d->left == -1 && d->right == -1)
    {
        // Queue is empty
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(deque *d)
{
    if (d->left == 0 && d->right == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int input()
{
    int val;
    printf("Enter New Value : ");
    scanf("%d", &val);
    return val;
}

// Inserting element at right hand side position
void insert_right(deque *d)
{
    if (is_empty(d))
    {
        // Queue is empty
        d->left = d->right = 0;
    }
    else if (is_full(d) || d->left == d->right + 1)
    {
        printf("Queue Is Full.\n");
        return;
    }
    else
    {
        // Queue is not empty neighter is full
        d->right += 1; // incrementing right pointer by 1 to store element
    }
    // Inserting element
    d->arr[d->right] = input();
}

// Inserting element at left hand side position
void insert_left(deque *d)
{
    if (is_empty(d))
    {
        // Queue is empty
        d->left = d->right = 0;
    }
    else if (is_full(d) || d->left == d->right + 1)
    {
        printf("Queue Is Full.\n");
        return;
    }
    else
    {
        if (d->left == 0)
        {
            d->left = MAX - 1; // if left is first element then again taking it to the last element
        }
        else
        {
            d->left -= 1;
        }
    }
    // Inserting element
    d->arr[d->left] = input();
}

void delete_right(deque *d)
{
    if (is_empty(d))
    {
        printf("Queue Empty.\n");
        return;
    }

    else if (d->left == d->right)
    {
        d->left = d->right = -1;
    }
    else
    {
        if (d->right == 0)
        {
            d->right = MAX - 1; // if right is at 0th position then again sending it to the last element
        }
        else
        {
            d->right -= 1;
        }
    }
}

void delete_left(deque *d)
{
    if (is_empty(d))
    {
        printf("Queue Empty.\n");
        return;
    }

    else if (d->left == d->right)
    {
        d->left = d->right = -1;
    }
    else
    {
        if (d->left == MAX - 1)
        {
            d->left = 0; // If left is at the last position then again taking it back to 1st position for deleting the 1st element.
        }
        else
        {
            d->left += 1;
        }
    }
}

void display(deque *d)
{
    int front = d->left;
    int rear = d->right;

    if (is_empty(d))
    {
        printf("Queue Empty.\n");
        return;
    }
    else
    {
        printf("Queue Elements Are : \n|");
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf(" %d |", d->arr[i]);
            }
        }
        else
        {
            for (int i = 0; i <= rear; i++)
            {
                printf(" %d |", d->arr[i]);
            }
            for (int i = front; i < MAX; i++)
            {
                printf(" %d |", d->arr[i]);
            }
        }
    }
}

void input_res(deque *d)
{
    int ch;
    while (1)
    {
        printf("\n\nInputed Restricted Queue.\n");
        printf("1 -> Insert At Right\n2-> Delete From Right\n3 -> Delete From Left\n4 -> Display\nEnter Choise : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            insert_right(d);
        }
        else if (ch == 2)
        {
            delete_right(d);
        }
        else if (ch == 3)
        {
            delete_left(d);
        }
        else if (ch == 4)
        {
            display(d);
        }
        else
        {
            break;
        }
    }
}

void output_res(deque *d)
{
    int ch;
    while (1)
    {
        printf("\n\nOutput Restricted Queue.\n");
        printf("1 -> Insert At Right\n2-> Insert From Left\n3 -> Delete From Left\n4 -> Display\nEnter Choise : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            insert_right(d);
        }
        else if (ch == 2)
        {
            insert_left(d);
        }
        else if (ch == 3)
        {
            delete_left(d);
        }
        else if (ch == 4)
        {
            display(d);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int c;
    deque *d = (deque *)malloc(sizeof(deque));
    d->left = -1;
    d->right = -1;
    printf("!-> Input Restricted Queue\n2 -> Output Restricted Queue\nEnter Choise : ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        input_res(d);
        break;
    case 2:
        output_res(d);
        break;
    }
    return 0;
}