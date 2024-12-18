#include<stdio.h>
int main()
{
    int n;
    printf("Enter Number : ");
    scanf("%d",&n);
    (n==0)?printf("0 Entered"):(n>0?printf("Positive Number"):printf("Negative Number"));
    return 0;
}