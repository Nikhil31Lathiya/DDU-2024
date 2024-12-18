#include <stdio.h>
#include <stdlib.h>
typedef struct stack
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

int peep(stack *s)
{
    return s->arr[s->top];
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

// void sort(stack *s, stack *s1)
// {
//     if (is_empty(s))
//     {
//         return;
//     }
//     else
//     {
//         if (is_empty(s1) || peep(s1) >= peep(s))
//         {
//             push(s1, pop(s));
//         }
//         else
//         {
//             int temp = pop(s);
//             if (is_empty(s1) ||peep(s1) > temp)
//             {
//                 push(s, pop(s1));
//                 sort(s, s1);
//             }
//             push(s1, temp);
//         }
//             sort(s, s1);
//     }
// }

void sort(stack *s, stack *s1)
{
    // Base case: if stack s is empty, return
    if (is_empty(s))
    {
        return;
    }
    else
    {
        int temp = pop(s); // Pop an element from s
        if (!is_empty(s1) && peep(s1) < temp)
        {
            push(s, pop(s1));
            // Recursively sort s1 again to ensure correct order
        }

        // Push temp onto s1
        push(s1, temp);
            sort(s1, s);
    }
}

void get_stk()
{
    stack *input = (stack *)malloc(sizeof(stack));
    if (input == NULL)
    {
        printf("Memory Allocation Failed.");
        return;
    }

    input->top = -1;
    int n, val;
    printf("Enter Number of elements : ");
    scanf("%d", &n);

    input->arr = (int *)malloc(n * sizeof(int));
    if (input->arr == NULL)
    {
        printf("Memory Allocation Failed.");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &val);
        push(input, val);
    }

    stack *temp = (stack *)malloc(sizeof(stack));
    temp->arr = (int *)malloc(n * sizeof(int));
    temp->top = -1;
    sort(input, temp);

    for (int i = 0; i <= temp->top; i++)
    {
        printf("%d\t", temp->arr[i]);
    }
}

int main()
{
    get_stk();
    return 0;
}
