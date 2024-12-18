#include <stdio.h>
int main()
{
    int n1, n2, lcm, low;

    printf("Enter num1 : ");
    scanf("%d", &n1);

    printf("Enter num2 : ");
    scanf("%d", &n2);

    low = n1 < n2 ? n1 : n2;

    while (1)
    {
        if (low % n1 == 0 && low % n2 == 0)
        {
            lcm = low;
            break;
        }
        low++;
    }

    printf("%d", lcm);
    return 0;
}