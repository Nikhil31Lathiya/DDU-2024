#include <stdio.h>
int main()
{
    int length;
    printf("enter matrix length ");
    scanf("%d", &length);
    int a[length][length], b[length][length], c[length][length], i, j;

    printf("Enter matrix 1:\n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter matrix 2:\n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("matrix 1:\n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("matrix 2:\n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
        printf("\n");
    }

    printf("sum of two matrix:\n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}