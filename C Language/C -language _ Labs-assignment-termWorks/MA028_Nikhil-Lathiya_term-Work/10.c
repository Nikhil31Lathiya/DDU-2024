#include <stdio.h>
int findgcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return findgcd(b, a % b);
    }
}
int main()
{
    int n1, n2;
    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);
    if (n1 < 0 || n2 < 0)
    {
        printf("Please enter non-negative numbers.\n");
        return 1;
    }
    int gcd = findgcd(n1, n2);
    printf("GCD of %d and %d is : %d\n", n1, n2, gcd);
    return 0;
}