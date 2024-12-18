#include <stdio.h>
int main()
{
    int i, j, n;

    printf("Enter the No : ");
    scanf("%d", &n);

    int z = n;

    for (i = 1; i <= n; i++)
    {

        for (j = z - 1; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("*", k);
        }
        printf("\n");
        z--;
    }

    for (i = n; i > 0; i--)
    {
        for (j = n - 1; j >= i; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}