#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1; // Base case: 0! and 1! are both 1
    }
    else
    {
        return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
    }
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is: %d\n", num, factorial(num));

    return 0;
}
