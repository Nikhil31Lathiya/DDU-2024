#include<stdio.h>
int main()
{
    int n=5 , sum =0;
    printf("Even No are : ");
    for(int i =1 ; i <=n ; i++)
    {
        printf("%d ", 2*i);
        sum += (2*i);
    }
    printf("\n sum : %d", sum);
return 0;
}