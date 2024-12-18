#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    // for printing the series
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    // to print the n th element
    // printf("%d ", fibonacci(n));

    return 0;
}
