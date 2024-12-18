// Implementation of basic stack
#include <stdio.h>
#include <stdlib.h>

// Structure for the stack
typedef struct
{
    char *stk;
    int top;
}stack;

// Checking if stack is empty or not
int isempty(stack *s)
{
    // -1 indicate that there is no element in the stack
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Checking if the size of the stack is full
int isfull(stack *s)
{
    if (s->top == 9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Pushing elements into the stack
void push(stack *s,char ele)
{
    if (!isfull(s))
    {
        s->stk[++s->top] = ele;
    }
    else
    {
        printf("\nStack Overflow\n");
    }
}

char pop(stack *s)
{
    if (!isempty(s))
    {
        char val = s->stk[s->top--];
        return val;
    }
    else
    {
        printf("\nStack Underflow\n");
        return 0;
    }
}

void display(stack *s)
{
    printf("|   |\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("| %c |\n",s->stk[i]);
        printf("|---|\n");
    }
}

int main()
{
    // Creating stack
    int n = 10; // stack of maximum size 10

    stack *s = (stack *)malloc(sizeof(stack));
    s->stk = (char *)malloc(sizeof(char));
    s->top = -1;

    push(s,'a');
    display(s);

    push(s,'b');
    display(s);

    push(s,'c');
    display(s);

    push(s,'d');
    display(s);

    push(s,'e');
    display(s);

    push(s,'f');
    display(s);

    push(s,'g');
    display(s);

    push(s,'h');
    display(s);

    push(s,'i');
    display(s);

    push(s,'j');
    display(s);

    push(s,'k');
    display(s);
    printf("\n\n%c Poped\n\n",pop(s));
    display(s);
    printf("\n\n");
    push(s,'l');

    return 0;
}