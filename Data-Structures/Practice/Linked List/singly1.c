#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; // data inserted in the node
    struct node *next; // next pointer to store the address of the next node
}*head=NULL, *new;
// head pointer to indicate starting of the list
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

// Insert at specific location
void ins_spe()
{
    int ind;
    printf("Enter Index : ");
    scanf("%d",&ind);
    if(ind == 1)
    {
        insert_first();
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
    }
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

// deleting at last
void del_last()
{
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
    temp->next = NULL;
}

void solve(struct node *s)
{
    if(s == NULL)
    {
        return;
    }
    printf("%d",s->data);
    if(s->next!=NULL)
    {
        solve(s->next->next);
    }
    printf("%d",s->data);
}

int main()
{
    for(int i =0;i<7;i++)
    {
        insert_last();
    }
    solve(head);
    return 0;
}