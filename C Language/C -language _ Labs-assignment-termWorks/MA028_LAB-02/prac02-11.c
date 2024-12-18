#include<stdio.h>
int main()
{
    int a,b,temp;
    printf("Enter 2 Numbers : ");
    scanf("%d %d",&a,&b);
    temp = a;
    a = b;
    b = temp;
    printf("Swapped Values a : %d , b : %d",a,b);
    return 0;
}