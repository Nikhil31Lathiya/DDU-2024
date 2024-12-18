#include <stdio.h>
int main()
{
    int i, j, k, n;

    printf("Enter the no : ");
    scanf("%d", &n);

    int z = n;

    for (i = 1; i <= n; i++)
    {
        printf("* ");
    }
    printf("\n");

    for (i = 1; i <= n - 2; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j == 1 || j == n)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        printf("* ");
    }

    return 0;
}