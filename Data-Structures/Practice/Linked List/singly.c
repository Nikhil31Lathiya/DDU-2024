#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;  // 5 6 
    struct node *next;
} *head = NULL, *new = NULL, *tail = NULL;

typedef struct node list;

// Creating new node
void create()
{
    new = (list *)malloc(sizeof(list));
    // checking if memory allocation was successfull
    if (new == NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    else
    {
        // assigning next node to null to avoid dangling pointer
        new->next = NULL;
        printf("Enter data to be inserted : ");
        scanf("%d", &new->data);
    }
}

// Inserting the created node at 1st position
void insert_at_front()
{
    create();
    if (head == NULL)
    {
        head = new;
        tail = new;
        new = NULL;
        return;
    }
    else
    {
        new->next = head;
        head = new;
        new = NULL;
        return;
    }
}

void insert_at_end()
{
    if(tail == NULL)
    {
        insert_at_front();
        return;
    }
    else
    {
        create(); // create a new node
        tail->next = new;
        tail = new;
        new = NULL;
        return;
    }
}

// Insert at specific location
void ins_spe()
{
    int ind;
    printf("Enter Index : ");
    scanf("%d",&ind);
    if(ind == 1)
    {
        insert_at_front();
        return;
    }
    else
    {
        create();
        struct node *temp;
        int i=1;
        temp = head;
        while(i<ind-1)
        {
            temp = temp->next;
            i++;
        }
        printf("%d",temp->data);
        struct node *succ;
        succ = temp->next;
        new->next = succ;
        temp->next = new;
        return;
    }
}

// deleting at first
void del_1st()
{
    if(head == NULL)
    {
        printf("Unable to delete list empty.");
        return;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
    } 
}

// eleting at last
void del_last()
{
    // printf("HI");
    if(head == NULL)
    {
        printf("Unable to delete list empty.");
        return;
    }
    int count = 0;
    struct node *temp;
    temp = head;
    while(temp->next->next != NULL)
    {   
        temp = temp->next;
        count++;
    }
    // temp = head;
    // int i=0;
    // while(i<count-1)
    // {
    //     temp = temp->next;
    //     printf("%d",temp->data);
    //     i++;
    // }
    struct node *a;
    a = temp->next;
    temp->next = NULL;
    free(a);
}



// void display list
void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Elements : \n");
        temp = head;
        int i = 1;
        while(temp!=NULL)
        {
            printf("Node : %d\t",i);
            printf("Value : %d\n",temp->data);
            temp = temp->next; // when last node is reached temp will automatically be initiated with null 
            i++;
        }
        printf("\n");
    }
}

int main()
{
    insert_at_front();
    for(int i =0;i<4;i++)
    {
        insert_at_end();
    }
    display();

    return 0;
}



