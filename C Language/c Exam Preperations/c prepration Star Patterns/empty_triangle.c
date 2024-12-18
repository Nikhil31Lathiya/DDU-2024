#include <stdio.h>
int main()
{
    int i, j, k, n;

    printf("Enter the no : ");
    scanf("%d", &n);

    int z = n;

    for (i = 1; i < n; i++)
    {
        for (j = n; j > i; j--)
        {
            printf("  ");
        }
        for (k = 1; k <= i; k++)
        {
            if (k == 1 || k == i)
            {
                printf("*   ");
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= n * 2 - 1; i++)
    {
        printf("* ");
    }
    return 0;
}