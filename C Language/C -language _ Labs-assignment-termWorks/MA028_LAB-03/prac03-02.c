#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%d %d",&x,&y);
    x=x+y;
    y=x-y;
    x=x-y;
    printf("After Swap x : %d, y : %d",x,y);
    return 0;
}