#include<stdio.h>

int fact(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }else{
        return n * fact(n-1);
    }
}

int main()
{
    int n;
    printf("Enter the value : ");
    scanf("%d",&n);

    if(n<0)
    {
        printf("please enter a non-negative integer..");
    }else{
        printf("Factorial of %d = %d\n",n,fact(n));
    }
    return 0;
}