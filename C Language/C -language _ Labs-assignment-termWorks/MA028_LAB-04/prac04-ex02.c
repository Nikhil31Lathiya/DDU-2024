#include<stdio.h>
int main()
{
    int s1,s2,s3;
    printf("Enter Sides : ");
    scanf("%d %d %d", &s1,&s2,&s3);
    if (s1==s2 && s2==s3)
    {
        printf("Equilateral Triangle");
    }
    else if(s1==s2 || s2==s3 || s1==s3)
    {
        printf("Isosceles Triangle");
    }
    else
    {
        printf("Scalene Triangle");
    }
    return 0;
}