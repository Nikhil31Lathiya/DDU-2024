#include <stdio.h>
int main()
{
    int i, j, k, n;

    printf("Enter no : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i += 2)
    {
        for (j = n; j > i; j--)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }

    for (i = n - 1; i > 0; i--)
    {
        for (j = n; j > i; j--)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}