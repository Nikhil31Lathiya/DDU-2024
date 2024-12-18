#include <stdio.h>
struct student
{
    int roll;
    char name[30];
    int marks[5];
} s1[3];

void get_val()
{
    printf("Enter Roll :");
    scanf("%d", &s1[0].roll);
    printf("Enter Name : ");
    scanf(" %s", s1[0].name);

    printf("Enter Marks Of 5 subjects : ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &s1[0].marks[i]);
    }
}
void display(float a[]);
int calc_marks()
{
    float details[2];
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + s1[0].marks[i];
    }
    sum = (float)sum;
    details[0] = sum;
    float percent = (sum * 100) / 500;
    details[1] = percent;
    display(details);
}

void display(float a[])
{
    printf("\nRoll : %d\n", s1[0].roll);
    printf("Name : %s\n", s1[0].name);
    printf("Total Marks : %.2f\n", a[0]);
    printf("Percentage : %.2f\n", a[1]);
}
int main()
{
    get_val();
    calc_marks();
    return 0;
}
