#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
// Defineing structure of stack as per question 1
typedef struct stack
{
    char stk[MAX];
    int top;
} stack1;

typedef struct num_stk
{
    int stk[MAX];
    int top;
} num_stk;

int is_num_empty(num_stk *n)
{
    if (n->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_num_full(num_stk *n)
{
    if (n->top == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void num_push(num_stk *s, int element)
{
    if (is_num_full(s))
    {
        printf("\nStack Overflow. Push failed.\n");
    }
    else
    {
        s->top += 1;
        s->stk[s->top] = element;
    }
}

int num_pop(num_stk *s)
{
    int element;
    if (is_num_empty(s))
    {
        return 0;
    }
    else
    {
        element = s->stk[s->top];
        s->top -= 1;
        return element;
    }
}

void num_display(num_stk *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("| %d |\n", s->stk[i]);
    }
    printf("|---|\n");
}

// Question 1 is_empty
int is_empty(stack1 *s)
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

// Question 1 is_full
int is_full(stack1 *s)
{
    if (s->top == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Question 1 push operation
void push(stack1 *s, char element)
{
    if (is_full(s))
    {
        printf("\nStack Overflow. Push failed.\n");
    }
    else
    {
        s->top += 1;
        s->stk[s->top] = element;
    }
}

// Question 1 pop operation
char pop(stack1 *s)
{
    char element;
    if (is_empty(s))
    {
        return 0;
    }
    else
    {
        element = s->stk[s->top];
        s->top -= 1;
        return element;
    }
}

// Question 1 peep operation
void peep(stack1 *s)
{
    if (is_empty(s))
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Top Element -> %c\n", s->stk[s->top]);
    }
}

// Question 1 disaplay operation
void display(stack1 *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("| %c |\n", s->stk[i]);
    }
    printf("|---|\n");
}

// Question 1 change operation
void change(stack1 *s, char ind, char new_val)
{
    char e;
    stack1 stk2;
    while (s->top > ind)
    {
        e = pop(s);
        push(&stk2, e);
    }
    s->stk[s->top] = new_val;
    while (!is_empty(&stk2))
    {
        e = pop(&stk2);
        push(s, e);
    }
    pop(s);
    printf("New Stack :- \n");
    display(s);
}

// Reverse a string in stack Question 2
void reverse()
{
    stack1 stk3;
    char c, rev[100];
    printf("\n\nEnter String To Reverse : ");
    while ((c = getchar()) != '\n')
    {
        push(&stk3, c);
    }
    int i = 0;
    while (stk3.top != -1)
    {
        rev[i] = pop(&stk3);
        i += 1;
    }
    rev[i] = '\0';
    printf("Reversed String : %s\n", rev);
}

// Operator precedence checker
int operator_precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Infix to postfix Question 2
void in_post()
{
    stack1 expression;
    expression.top = -1;
    char c, postfix[100];
    char pop_char;
    int i = 0, iteration = 1;
    getchar();
    printf("Enter Infix Expression : ");
    while ((c = getchar()) != '\n')
    {
        if (c == '(')
        {
            push(&expression, c);
        }
        else if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
        {
            if (is_empty(&expression))
            {
                push(&expression, c);
            }
            else
            {
                if (operator_precedence(expression.stk[expression.top]) > operator_precedence(c))
                {
                    while (!is_empty(&expression))
                    {
                        postfix[i] = pop(&expression);
                        i += 1;
                    }
                    push(&expression, c);
                }
                else if (operator_precedence(expression.stk[expression.top]) < operator_precedence(c))
                {
                    push(&expression, c);
                }
            }
        }

        else if (isalpha(c))
        {
            postfix[i] = c;
            i += 1;
        }
        else if (c == ')')
        {
            while (expression.stk[expression.top] != '(')
            {
                if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
                {
                    postfix[i] = pop(&expression);
                    i += 1;
                }
                else
                {
                    pop(&expression);
                }
            }
            if (expression.stk[expression.top] == '(')
            {
                pop(&expression);
            }
        }
        display(&expression);
    
        printf("\n\nPostfix Expression : %s\n", postfix);
    }

    while (!is_empty(&expression))
    {
        postfix[i] = pop(&expression);
        i += 1;
    }
    printf("\n\nPostfix Expression : %s\n", postfix);
}

// Postfix expression evaluation
void postfix_evaluation()
{
    num_stk number_stack;
    number_stack.top = -1;
    char c;
    getchar();
    int temp;
    printf("Enter Postfix Expression In Numbers : ");
    while ((c = getchar()) != '\n')
    {
        if (isdigit(c))
        {
            num_push(&number_stack, c - '0');
        }
        else if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
        {
            int a = num_pop(&number_stack);
            int b = num_pop(&number_stack);
            if (c == '+')
            {
                num_push(&number_stack, b + a);
            }
            else if (c == '-')
            {
                num_push(&number_stack, b - a);
            }
            else if (c == '*')
            {
                num_push(&number_stack, b * a);
            }
            else if (c == '/')
            {
                num_push(&number_stack, b / a);
            }
            else if (c == '^')
            {
                int result = 1;
                for (int i = 0; i < a; i++)
                {
                    result = result * b;
                }
                printf("%d", result);
                num_push(&number_stack, result);
            }
        }
        // num_display(&number_stack);
    }
    printf("\nResult : %d\n", num_pop(&number_stack));
}

int main()
{
    int choise;
    stack1 stk1;
    stk1.top = -1;
    while (1)
    {
        printf("Enter Choise :\n1 for Push.\n2 For Pop.\n3 For Change.\n4 To Check Empty.\n5 To Check Full.\n6 To Peep.\n7 To Display.\n8 To Reverse String.\n9 For Infix-To-Postfix.\n10 For Postfix Evaluation.\n11 TO Exit.\n");

        scanf("%d", &choise);
        if (choise == 1)
        {
            char p;
            getchar();
            printf("Enter Character To Push :");
            scanf("%c", &p);
            push(&stk1, p);
        }
        else if (choise == 2)
        {
            char p = pop(&stk1);
            if (p == 0)
            {
                printf("Stack Underflow.Pop Failed.\n");
            }
            else
            {
                printf("%c -> Poped.\n", p);
            }
        }
        else if (choise == 3)
        {
            char p;
            int ind;
            printf("Enter The Index : ");
            scanf("%d", &ind);
            printf("Enter New Character : ");
            scanf("%c", &p);
            change(&stk1, ind, p);
        }
        else if (choise == 4)
        {
            if (is_empty(&stk1))
            {
                printf("Stack Empty.\n");
            }
            else
            {
                printf("Stack Not Empty.\n");
            }
        }
        else if (choise == 5)
        {
            if (is_full(&stk1))
            {
                printf("Stack Full.\n");
            }
            else
            {
                printf("Stack Not Full.\n");
            }
        }
        else if (choise == 6)
        {
            peep(&stk1);
        }
        else if (choise == 7)
        {
            display(&stk1);
        }
        else if (choise == 8)
        {
            reverse();
        }
        else if (choise == 9)
        {
            in_post();
        }
        else if (choise == 10)
        {
            postfix_evaluation();
        }
        else
        {
            break;
        }
    }
    return 0;
}

// 623+-382/+*2^3+