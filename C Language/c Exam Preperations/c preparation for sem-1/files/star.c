#include <stdio.h>
int main()
{
    int n;
    printf("Enter Num : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < 5; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}