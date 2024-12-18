// Copy one list to another
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *new_o = NULL, *head_o = NULL, *tail_o = NULL;
node *new_dup = NULL, *head_dup = NULL, *tail_dup = NULL;

// Create a new element in the original list
void create()
{
    new_o = (node *)malloc(sizeof(node));
    if (new_o == NULL)
    {
        printf("Memory Allocation Failed.");
        return;
    }
    else
    {
        new_o->next = NULL;
        printf("Enter Value : ");
        scanf("%d", &new_o->data);
        return;
    }
}

void insert_at_front()
{
    create();
    if (head_o == NULL)
    {
        head_o = new_o;
        tail_o = new_o;
        new_o = NULL;
        return;
    }
    else
    {
        new_o->next = head_o;
        head_o = new_o;
        new_o = NULL;
        return;
    }
}

void insert_at_end()
{
    if(head_o == NULL)
    {
        insert_at_front();
        return;
    }
    else
    {
        create();
        tail_o->next = new_o;
        tail_o = new_o;
        new_o = NULL;
        return;
    }
}

void display_ori()
{
    node *temp = head_o;
    printf("Original Data : \n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_dup()
{
    node *temp = head_dup;
    printf("Duplicate Data : \n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp= temp->next;
    }
    printf("\n");
}

void copy_list()
{
    node *temp;
    temp = head_o;
    while(temp!=NULL)
    {
        new_dup = (node *) malloc(sizeof(node));
        new_dup->data = temp->data;
        new_dup->next = NULL;
        if(head_dup == NULL)
        {
            head_dup = new_dup;
            tail_dup = new_dup;
        }
        else
        {
            tail_dup->next = new_dup;
            tail_dup = new_dup;
        }
        temp = temp->next;
    }
    display_ori();
    display_dup();
}

int main()
{
    insert_at_front();
    for (int i = 0; i < 4; i++)
    {
        insert_at_end();
    }

    copy_list();
    
    return 0;
}