#include <stdio.h>

int main()
{
    int i, j, k, d = 2;

    printf("*\n");
    for (i = 1; i <= 3; i++)
    {
        if (i == 0)
        {
            printf("*");
        }
        else
        {
            printf("*");

            for (j = 1; j <= i; j++)
            {
                printf("%d", j);
            }
            for (k = j - 2; k >= 1; k--)
            {
                printf("%d", k);
            }
            printf("*");
        }
        printf("\n");
    }
    for (i = i - 2; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("*");
        }
        else
        {
            printf("*");

            for (j = 1; j <= i; j++)
            {
                printf("%d", j);
            }
            for (k = j - 2; k >= 1; k--)
            {
                printf("%d", k);
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
