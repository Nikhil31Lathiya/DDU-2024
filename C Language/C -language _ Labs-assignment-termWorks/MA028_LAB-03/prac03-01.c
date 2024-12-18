#include<stdio.h>
int main()
{
    int marks;
    printf("Enter Marks : ");
    scanf("%d",&marks);
    if (marks>=90)
    {
        printf("Grade A");
    }
    else if(marks>=80)
    {
        printf("Grade B");
    }
    else if(marks>=65)
    {
        printf("Grade C");
    }
    else
    {
        printf("Grade D");
    }
    return 0;
}