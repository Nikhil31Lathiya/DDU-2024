#include<stdio.h>

int fun(int n)
{
    int l = 0;
    while(n != 1)
    {
        if(n%2 == 0)
        {
            n = n / 2;
        }else{
            n = 3 * n + 1;
        }
        l++;
    }
    return l;
}

int main()
{
    int a,b;
    scanf("%d",&a);
    b= fun(a);
    printf("%d",b);
    return 0;
}
