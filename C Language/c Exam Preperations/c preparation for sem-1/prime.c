#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter the starting num: ");
    scanf("%d", &n);

    printf("Enter the ending num: ");
    scanf("%d", &m);

    printf("Prime numbers up to %d: ", n);

    for (int i = n; i <= m ; i++)
    {
        int count = 0;

        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
