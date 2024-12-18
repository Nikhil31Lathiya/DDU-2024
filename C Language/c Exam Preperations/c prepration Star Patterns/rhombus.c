#include <stdio.h>
int main()
{
    int i, j, k, n;

    printf("Enter the no : ");
    scanf("%d", &n);
    int z = n;

    for (i = 1; i <= n; i++)
    {
        for (j = z - 1; j > 0; j--)
        {
            printf(" ");
        }
        for (k = n; k > 0; k--)
        {
            printf("* ");
        }
        printf("\n");
        z--;
    }

    return 0;
}