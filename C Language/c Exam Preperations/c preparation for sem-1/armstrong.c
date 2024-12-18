#include <stdio.h>
int main()
{
    int num, a, arm = 0, c;

    printf("Enter num : ");
    scanf("%d", &num);
    c = num;
    while (num > 0)
    {
        a = num % 10;
        arm = arm + (a * a * a);
        num /= 10;
    }

    if (c == arm)
    {
        printf("Armstrong");
    }
    else
    {
        printf("Armstrong not ");
    }
    return 0;
}