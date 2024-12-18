#include <stdio.h>
int main()
{
    int i, j, k, n, val;

    printf("Enter the no : ");
    scanf("%d", &n);
    int z = n;

    for (i = 1; i <= n; i++)
    {
        for (j = z; j > 0; j--)
        {
            printf(" ");
        }
        int c = 1;

        for (k = 1; k <= i; k++)
        {
            printf("%d ", c);
            c = c * (i - k) / k;
        }
        printf("\n");
        z--;
    }
    return 0;
}