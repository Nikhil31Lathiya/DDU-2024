#include <stdio.h>
struct student
{
    int roll;
    int marks[5];
    int total;
    float percent;
};

void get_stud(struct student *p)
{
    int m_sum = 0;
    float per;
    printf("Enter Student Details : \n");
    for (int i = 0; i < 2; i++)
    {
        printf("\nRoll : ");
        scanf("%d", &p[i].roll);
        printf("Enter Marks : \n");
        for (int j = 0; j < 5; j++)
        {
            printf("Subject %d : ", j + 1);
            scanf("%d", &p[i].marks[j]);
        }
    }
}

void display(struct student *p)
{
    for (int j = 0; j < 2; j++)
    {
        printf("\nRoll : %d\n", p[j].roll);
        printf("Marks : \n");
        for (int i = 0; i < 5; i++)
        {
            printf("Subject %d -> %d\n", i + 1, p[j].marks[i]);
        }
        printf("Total : %d\n", p[j].total);
        printf("Percent : %f\n", p[j].percent);
    }
}

void compute(struct student *p)
{
    int m_sum = 0;
    float per;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            m_sum += p[i].marks[j];
        }
        p[i].total = m_sum;
        p[i].percent = (m_sum * 100.0) / 500;
        m_sum = 0;
    }
}

int main()
{
    struct student s1;
    struct student *ptr ;
    ptr = &s1;
 
 
 
 
    get_stud(ptr);
    compute(ptr);
    display(ptr);
    return 0;
}