#include <stdio.h>

struct student
{
    int r_no;
    char name[50];
    int marks[2];
    int total;
    float per;
} s[3];

void getData(struct student s[])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter roll No for student %d: ", i + 1);
        scanf("%d", &s[i].r_no);
        printf("Enter Name for student %d: ", i + 1);
        scanf("%s", s[i].name);
        for (int j = 0; j < 2; j++)
        {
            printf("Enter marks for sub %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }
}

void calaData(struct student s[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            s[i].total += s[i].marks[j];
        }
        s[i].per = ((float)s[i].total / 200) * 100; // Use float in the calculation
        // printf("\nTotal marks of student %d is %d", i + 1, s[i].total);
        // printf("\nTotal per of student %d is %.2f%%", i + 1, s[i].per);
    }
}

void printData(struct student s[])
{
    for (int i = 0; i < 3; i++)
    {
        printf(" roll No for student %d: ", s[i].r_no);
        printf("\n Name for student %s: ", s[i].name);
        printf("\n Total marks for student %d: ", s[i].total);
        printf("\n Total Per for student %f : ", s[i].per);
    }
}

int main()
{
    getData(s);
    calaData(s);
    printData(s);
    return 0;
}
