#include<stdio.h>
int main()
{
    int n=5, f=1;

    for(int i=1 ; i<=n ; i++)
    {
        f= f*i;
    }
    printf("fact is %d ", f);
    return 0;
}