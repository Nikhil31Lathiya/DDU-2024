#include<stdio.h>
int main()
{
    int year;
    printf("Enter Year : ");
    scanf("%d",&year);
    ((year%4==0 && year%100!=0)||(year%400==0)?printf("Leap Year"):printf("Not A Leap Year"));
    return 0;
}