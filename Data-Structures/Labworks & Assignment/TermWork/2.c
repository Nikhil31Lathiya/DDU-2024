#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    char data;
    struct node *next;
};

typedef struct node node;

node *head = NULL;
node *tail = NULL;

void push(char c)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory Allocation Failed.");
        exit(1);
    }
    new_node->data = c;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

char pop()
{
    if (head == NULL)
    {
        printf("Stack is empty.");
        exit(1);
    }

    char data = tail->data;
    if (head == tail)
    {
        free(tail);
        head = tail = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
    return data;
}

int is_empty()
{
    return head == NULL;
}

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
    else if (op == '(')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void in_post()
{
    char c, postfix[100];
    int i = 0;

    printf("Enter infix expression : ");
    while ((c = getchar()) != '\n')
    {
        if (isalpha(c))
        {
            postfix[i++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (!is_empty() && tail->data != '(')
            {
                postfix[i++] = pop();
            }
            if (!is_empty() && tail->data == '(')
            {
                pop(); // Discard '('
            }
            else
            {
                printf("Mismatched parentheses.");
                exit(1);
            }
        }
        else if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
        {
            while (!is_empty() && operator_precedence(tail->data) >= operator_precedence(c))
            {
                postfix[i++] = pop();
            }
            push(c);
        }
    }

    while (!is_empty())
    {
        if (tail->data == '(')
        {
            printf("Mismatched parentheses.");
            exit(1);
        }
        postfix[i++] = pop();
    }

    postfix[i] = '\0'; // Null terminate the string
    printf("Postfix Expression : %s\n", postfix);
}

int main()
{
    in_post();
    return 0;
}
 