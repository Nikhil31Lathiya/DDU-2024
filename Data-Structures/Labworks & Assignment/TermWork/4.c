#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int cust_id;
    char name[100];
    long int phone_number;
    struct node *next;
} node;

int count = 0;

node *create(int c, char *n, long int p)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->cust_id = c;
    temp->phone_number = p;
    strcpy(temp->name, n);
    temp->next = NULL;
    count++;
    return temp;
}

void insert_first(node **head, int c, char *n, long int p)
{
    node *temp = create(c, n, p);
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head; 
    }
    else
    {
        temp->next = *head;
        node *last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = temp;
        *head = temp;
    }
}

void insert_last(node **head, int c, char *n, long int p)
{
    node *temp = create(c, n, p);
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head; 
    }
    else
    {
        node *last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = temp;
        temp->next = *head;
    }
}

void delete_first(node **head)
{
    if (*head == NULL)
        return;
    node *temp = *head;
    node *last = *head;
    while (last->next != *head)
        last = last->next;
    if (last == *head)
    {
        *head = NULL;
        free(temp);
        return;
    }
    *head = temp->next;
    last->next = *head;
    free(temp);
}

void delete_last(node **head)
{
    if (*head == NULL)
        return;
    node *temp = *head;
    node *last = *head;
    while (last->next != *head)
    {
        temp = last;
        last = last->next;
    }
    if (last == *head)
    {
        *head = NULL;
        free(last);
        return;
    }
    temp->next = *head;
    free(last);
}

void insert_sorted(node **head, int c, char *n, long int p)
{
    node *temp = create(c, n, p);
    if (*head == NULL || c < (*head)->cust_id)
    {
        temp->next = *head;
        node *last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = temp;
        *head = temp;
    }
    else
    {
        node *current = *head;
        while (current->next != *head && current->next->cust_id < c)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void delete_from(node **head, int pos)
{
    if (*head == NULL)
        return;
    if (pos == 0)
    {
        delete_first(head);
        return;
    }
    node *prev = NULL;
    node *current = *head;
    for (int i = 0; i < pos; i++)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    count--;
    free(current);
}

void search_name(node *head, char name[100])
{
    node *temp = head;
    int h = 1;
    do
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("%d %s %ld -> ", temp->cust_id, temp->name, temp->phone_number);
            h = 0;
        }
        temp = temp->next;
    } while (temp != head);
    if (h)
    {
        printf("not found");
    }
}

void search_id(node *head, int id)
{
    node *temp = head;
    int h = 1;
    do
    {
        if (temp->cust_id == id)
        {
            printf("%d %s %ld -> ", temp->cust_id, temp->name, temp->phone_number);
            h = 0;
        }
        temp = temp->next;
    } while (temp != head);
    if (h)
    {
        printf("not found");
    }
}

void search_phoneno(node *head, long int phoneno)
{
    node *temp = head;
    int h = 1;
    do
    {
        if (temp->phone_number == phoneno)
        {
            printf("%d %s %ld -> ", temp->cust_id, temp->name, temp->phone_number);
            h = 0;
        }
        temp = temp->next;
    } while (temp != head);
    if (h)
    {
        printf("not found");
    }
}

void delete_name(node **head, char name[100])
{
    if (*head == NULL)
        return;
    node *temp = *head;
    node *prev = NULL;
    do
    {
        if (strcmp(temp->name, name) == 0)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    if (temp == NULL || temp->next == *head)
    {
        printf("not found.\n");
        return;
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    count--;
    free(temp);
}

void delete_id(node **head, int id)
{
    if (*head == NULL)
        return;
    node *temp = *head;
    node *prev = NULL;
    do
    {
        if (temp->cust_id == id)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    if (temp == NULL || temp->next == *head)
    {
        printf("not found.\n");
        return;
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    count--;
    free(temp);
}

void delete_phoneno(node **head, long int phoneno)
{
    if (*head == NULL)
        return;
    node *temp = *head;
    node *prev = NULL;
    do
    {
        if (temp->phone_number == phoneno)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    if (temp == NULL || temp->next == *head)
    {
        printf("not found.\n");
        return;
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    count--;
    free(temp);
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("empty.\n");
        return;
    }

    node *current = head;
    node *index = NULL;
    int temp_id;
    char temp_name[100];
    long int temp_phone;

    do
    {
        index = current->next;

        while (index != head)
        {
            if (current->cust_id > index->cust_id)
            {
                temp_id = current->cust_id;
                current->cust_id = index->cust_id;
                index->cust_id = temp_id;

                strcpy(temp_name, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, temp_name);

                temp_phone = current->phone_number;
                current->phone_number = index->phone_number;
                index->phone_number = temp_phone;
            }
            index = index->next;
        }
        current = current->next;
    } while (current->next != head);
    current = head;
    do
    {
        printf("%d %s %ld -> ", current->cust_id, current->name, current->phone_number);
        current = current->next;
    } while (current != head);
    printf("\n");
}


int main()
{
    node *head = NULL;
    int choice = 1;
    while (choice != 0)
    {
        int c;
        char n[100];
        long int p;
        printf("\n1. insert from first\n2. insert from last\n3. insert at directory sorting position based on cust id\n4. delete from specific position\n5. delete from first\n6. delete from last\n7. display \n8. search by name\n9. search by cust id\n10. search by phone number\n11. delete by name\n12. delete by cust id\n13. delete by phone number\n0.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d %s %ld", &c, n, &p);
            insert_first(&head, c, n, p);
            break;
        case 2:
            scanf("%d %s %ld", &c, n, &p);
            insert_last(&head, c, n, p);
            break;
        case 3:
            scanf("%d %s %ld", &c, n, &p);
            insert_sorted(&head, c, n, p);
            break;
        case 4:
            printf("enter position to delete: ");
            scanf("%d", &c);
            delete_from(&head, c);
            break;
        case 5:
            delete_first(&head);
            break;
        case 6:
            delete_last(&head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("enter name: ");
            scanf("%s", n);
            search_name(head, n);
            break;
        case 9:
            printf("enter customer id: ");
            scanf("%d", &c);
            search_id(head, c);
            break;
        case 10:
            printf("enter phone number: ");
            scanf("%ld", &p);
            search_phoneno(head, p);
            break;
        case 11:
            printf("enter name : ");
            scanf("%s", n);
            delete_name(&head, n);
            break;
        case 12:
            printf("enter customer id : ");
            scanf("%d", &c);
            delete_id(&head, c);
            break;
        case 13:
            printf("enter phone number : ");
            scanf("%ld", &p);
            delete_phoneno(&head, p);
            break;
        case 0:
        default:
            break;
        }
    }
    return 0;
}