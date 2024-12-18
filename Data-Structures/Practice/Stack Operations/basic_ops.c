#include<stdio.h>
#define MAX 10
struct stack{
    char stk[MAX];
    int top;
};
int push(struct stack *p,char ch)
{
    if(p->top == MAX)
    {
        return 0;
    }
    else
    {
        p->top+=1;
        p->stk[p->top]=ch;
        return 1;
    }
}

char pop(struct stack *p)
{
    if(p->top<0)
    {
        printf("Underflow");
        return 0;
    }
    else
    {
        char ch;
        ch = p->stk[p->top];
        p->top -=1;
        return ch;
    }
}



int main()
{
    struct stack s;
    s.top = -1;
    if(push(&s,'j'))
    {
        printf("Done\n");
    }
    else
    {
        printf("Failed");
    }

    if(push(&s,'a'))
    {
        printf("Done\n");
    }
    else
    {
        printf("Failed");
    }

    char a = pop(&s);

    printf("\n%c",a);
    return 0;
}
