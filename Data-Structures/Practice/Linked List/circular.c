#include<stdio.h>
#include<stdlib.h>
struct node{
    int data; // data inserted in the node
    struct node *next; // next pointer to store the address of the next node
}*head=NULL, *new,*tail=NULL;

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

void insert_first()
{
    create();
    if (head==NULL && tail == NULL)
    {
        head = new;
        tail = new;
        tail->next = head;
        // return;
    }
    else
    {
        new->next = head;
        head = new;
        tail->next = head;
        new = NULL;
    }
}

void insert_last()
{

    if(head==NULL && tail==NULL)
    {
        insert_first();
    }
    else
    {
        // created a new node
        create();
        tail->next = new;
        new->next = head;
        tail = new;
        new = NULL;
    }    
}

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

void delete_front()
{
    if(head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        tail->next = head;
        temp = NULL;
    }
}

void delete_end()
{
    if(head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        struct node *temp;
        temp = head;
        while(temp->next!=tail)
        {
            temp = temp->next;
        }
        tail = temp;
        tail->next = head;
    }
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
        while(1)
        {
            printf("Node : %d\t",i);
            printf("Value : %d\n",temp->data);
            temp = temp->next; // when last node is reached temp will automatically be initiated with null 
            if(temp==tail->next)
            {
                break;
            }
            i++;
        }
        printf("\n");
    }
}


int main()
{
    insert_first();
    for(int i =0;i<4;i++)
    {
        insert_last();
    }
    display();

    ins_spe();
    display();

    delete_front();
    display();

    delete_end();
    printf("After Deletion\n");
    display();
}