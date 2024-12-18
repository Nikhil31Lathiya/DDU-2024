#include <stdio.h>
int main()
{
    int n1, n2, gcd;

    printf("Enter num1 : ");
    scanf("%d", &n1);

    printf("Enter num2 : ");
    scanf("%d", &n2);

    for (int i = 1; i <= n1 && i <= n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    printf("\n%d ", gcd);
    return 0;
}