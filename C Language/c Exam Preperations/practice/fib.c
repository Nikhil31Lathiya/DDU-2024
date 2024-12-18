#include<stdio.h>

void fib(int);

int main()
{
    int n;

    printf("Enter Number : ");
    scanf("%d", &n);

    fib(n);

return 0;
}


void fib(int n)
{
    int a=0 , b=1 , c;

    for(int i=1 ; i<=n ; i++)
    {
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
}