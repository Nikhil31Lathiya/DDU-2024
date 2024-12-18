#include <stdio.h>

int main()
{
    int i, j, k;

    for (i = 0; i < 5; i++)
    {
        for (j = 5; j > i; j--)
        {
            printf("* ");
        }
        for (k = 0; k < i; k++)
        {
            printf("  ");
        }

        for (j = 0; j < i; j++)
        {
            printf("  ");
        }
        for (k = 5; k > i; k--)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("* ");
        }
        for (k = 4; k > i; k--)
        {
            printf("  ");
        }

        for (j = 4; j > i; j--)
        {
            printf("  ");
        }
        for (k = 0; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
