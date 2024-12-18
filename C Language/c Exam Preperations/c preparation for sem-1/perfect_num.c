#include <stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter no ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {

        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == n)
    {
        printf("Perfect num");
    }
    else
    {
        printf("not perfect ");
    }
    return 0;
}