// Reversing a linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; // data inserted in the node
    struct node *next; // next pointer to store the address of the next node
}*head=NULL, *new;
// head pointer to indicate starting of the list
typedef struct node node;

// newnode pointer to create a newnode
void create()
{
    new = (struct node *) malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("Node Creation failed");
        return;
    }
    
    // Being initialized to null to avoid dangling pointer
    new->next = NULL;
    printf("Enter Value for new node : ");
    scanf("%d",&new->data);
}

// Inserting as first node
void insert_first()
{
    create();
    if (head==NULL)
    {
        head = new;
        return;
    }
    else
    {
        new->next = head;
        head = new;
        new = NULL;
    }
}

// insert ar last
void insert_last()
{
    
    // Traverse to last
    struct node *temp;
    if(head==NULL)
    {
        insert_first();
    }
    else
    {
        // created a new node
        create();
        temp = head;
        // taking next node of temp so that new address can be assigned to last node
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }            
}

void reverse ()
{
    node *temp,*temp2;
    while(head!=NULL)
    {
        temp2 = head->next;
        head->next = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
}

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
    for(int i =0;i<5;i++)
    {
        insert_last();
    }
    display();
    
    reverse();
    display();
    return 0;
}