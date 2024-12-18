#include <stdio.h>
int main()
{
    int a, b, c;

    printf("Enter num 1 ");
    scanf("%d", &a);

    printf("Enter num 2 ");
    scanf("%d", &b);

    while (a > 0)
    {
        a--;
        b++;
    }
    printf("\n %d\n", b);
    return 0;
}