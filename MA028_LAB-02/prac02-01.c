#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter 3 Numbers : ");
    scanf("%d %d %d",&a, &b,&c);

    (a>c)?(b>c?printf("%d",b):printf("%d",c)):printf("%d",c);
    return 0;
}