#include <stdio.h>
int main()
{
    int i, j, k, n;
    int z = n;

    printf("Enter the no : ");
    scanf("%d", &n);

    for (i = n - 1; i > 1; i--)
    {
        for (j = n; j > i; j--)
        {
            printf("  ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("*   ");
        }
        printf("\n");
    }

    for (i = 1; i < n; i++)
    {
        for (j = n; j > i; j--)
        {
            printf("  ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("*   ");
        }
        z--;
        printf("\n");
    }
    return 0;
}