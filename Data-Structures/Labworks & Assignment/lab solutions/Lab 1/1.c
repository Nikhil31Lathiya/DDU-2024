#include<stdio.h>
#include<stdlib.h>


struct student
{
    char name[100];
    int idno;
    int total_marks;
};

// Get student details
void get_stud(struct student *p, int size)
{
    printf("Enter Student Data : \n");
    for(int i=0;i<size;i++)
    {
        printf("\nEnter Name : ");
        scanf("%s",p[i].name);
        printf("Enter Student Id : ");
        scanf("%d",&p[i].idno);
        printf("Enter Total Marks : ");
        scanf("%d",&p[i].total_marks);
    }
}

// Get student details
void display(struct student *p, int size)
{
    printf("---------------------------------------------------------------\n");
    for(int i=0;i<size;i++)
    {
        // printf("hi");
        printf("\nName : %s\n",p[i].name);
        printf("Student Id : %d\n",p[i].idno);
        printf("Total Marks : %d\n",p[i].total_marks);
    }
    printf("---------------------------------------------------------------\n");
}

// Void filter
void filter(struct student *p, int size, int limit)
{
    printf("---------------------------------------------------------------\n");
    printf("Filtered Data.");
    for(int i=0;i<size;i++)
    {
        if(p[i].total_marks<limit)
        {
            printf("\n\nName : %s\n",p[i].name);
            printf("Id : %d\n",p[i].idno);
            printf("Marks : %d\n",p[i].total_marks);
        }
    }
    printf("---------------------------------------------------------------\n");
} 

int main(int argc, char *argv[])
{
    int N,M;
    N = atoi(argv[1]);
    M = atoi(argv[2]);

    struct student s1[20];
    struct student *ptr;
    ptr = s1;

    get_stud(ptr,N);

    display(ptr,N);

    filter(ptr,N,M);
    return 0;
}

