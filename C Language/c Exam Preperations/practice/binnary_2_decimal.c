#include<stdio.h>
int main()
{
    int d=0, base=1,n,r;

    printf("Enter the binnary No : ");
    scanf("%d", &n);

    while(n > 0)
    {
        r= n%10;
        d= d + r*base;
        n= n/10;
        base = base*2;
    }
printf("%d ", d);

return 0;
}