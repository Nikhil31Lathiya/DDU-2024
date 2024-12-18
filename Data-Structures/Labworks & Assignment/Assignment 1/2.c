// C program to sort a stack using temporary stack
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *arr;
    int top;
} stack;

void push(stack *s, int element)
{
    s->top += 1;
    s->arr[s->top] = element;
}

int pop(stack *s)
{
    int element = s->arr[s->top];
    s->top -= 1;
    return element;
}

int is_empty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peep(stack *s)
{
    return s->arr[s->top];
}

void display(stack *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("| %d |\n", s->arr[i]);
    }
    printf("|----|");
}

void sort(stack *s, int size)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }
    temp->top = -1;
    temp->arr = (int *)malloc(size * sizeof(int));
    if (temp->arr == NULL)
    {
        printf("Memory allocation failed.");
        return;
    }
    while (!is_empty(s))
    {
        if (is_empty(temp))
        {
            push(temp, pop(s));
        }
        else
        {
            int temp_pop = pop(s);
            while (peep(temp) > temp_pop)
            {
                push(s, pop(temp));
            }
            push(temp, temp_pop);
        }
    }
    display(temp, size);
}

int main()
{
    stack *s1 = (stack *)malloc(sizeof(stack));
    if (s1 == NULL)
    {
        printf("Memory Allocation Falied");
        return 0;
    }
    s1->top = -1;
    int n, val;
    printf("Enter length of stack : ");
    scanf("%d", &n);

    s1->arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter Value %d : ", i + 1);
        scanf("%d", &val);
        push(s1, val);
    }

    sort(s1, n);
    return 0;
}