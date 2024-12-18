#include <stdio.h>

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

void printfibo(int n)
{
    printf("fibonacci series up to %d terms : ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibo(i));
    }
    printf("\n");
}

int main()
{
    int n;

    printf("enter number of fibonacci series : ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("please enter non nagetive number.\n");
        return 1;
    }

    printfibo(n);

    return 0;
}
