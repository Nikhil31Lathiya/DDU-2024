#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
} *new = NULL, *top = NULL, *head = NULL;

typedef struct stack stack;

void create()
{
    new = (stack *)malloc(sizeof(stack));
    if (new == NULL)
    {
        printf("Memory Allocation Failed.");
        return;
    }
    new->next = NULL;
    printf("Enter Value : ");
    scanf("%d", &new->data);
}

int is_empty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
{
    create();
    if (is_empty())
    {
        top = new;
        head = new;
        return;
    }
    else
    {
        top->next = new;
        top = new;
    }
    new = NULL;
}

void pop()
{
    if (is_empty())
    {
        printf("Stack Empty");
        return;
    }
    else
    {
        stack *temp;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        stack *a = temp->next;
        top = temp;
        top->next = NULL;
        temp->next = NULL;
        free(a);
    }
}

void peep()
{
    printf("| %d |",top->data);
}

void display()
{
    stack *temp;
    temp = head;
    printf("|");
    while (temp!= NULL)
    {
        printf("%d |",temp->data);
        temp = temp->next;
    }
}

int main()
{
    for(int i=0;i<4;i++)
    {
        push();
    }
    display();
    printf("\nAfter POP\n");
    pop();
    display();

    printf("\nPeep\n");
    peep();
    return 0;
}