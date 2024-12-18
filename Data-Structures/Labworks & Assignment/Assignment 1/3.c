#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack
{
    char arr[MAX];
    int top;
} stack;

void push(stack *s, char element)
{
    s->top += 1;
    s->arr[s->top] = element;
}

char pop(stack *s)
{
    char element = s->arr[s->top];
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

char peep(stack *s)
{
    return s->arr[s->top];
}

void sort(stack *s)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }
    temp->top = -1;
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
    push(temp, '\n');
    int count = 0;
    while (!is_empty(temp))
    {
        push(s, pop(temp));
        count++;
    }
    push(s, '\n');

    for (int i = count; i > 0; i--)
    {
        printf("%c", s->arr[i]);
    }
}

void input()
{
    stack *input = (stack *)malloc(sizeof(stack));
    if (input == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }
    input->top = -1;
    char c;
    printf("Enter String : ");
    while ((c = getchar()) != '\n')
    {
        push(input, c);
    }
    sort(input);
}

int main()
{
    input();
    return 0;
}