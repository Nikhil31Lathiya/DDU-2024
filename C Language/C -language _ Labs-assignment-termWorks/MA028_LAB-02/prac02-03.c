#include<stdio.h>
int main()
{
    int M,N,q,r;
    printf("Enter 2 Numbers :");
    scanf("%d %d",&M ,&N);
    q=M/N;
    r=M%N;
    printf("Quotient : %d \n Remainder : %d",q,r);
    return 0;
}