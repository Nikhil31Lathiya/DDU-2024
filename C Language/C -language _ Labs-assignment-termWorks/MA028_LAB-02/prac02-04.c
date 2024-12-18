#include<stdio.h>
int main()
{
    float p,r,n,i;
    printf("Enter P , R , N :");
    scanf("%f %f %f",&p,&r,&n);
    i=(p*r*n)/100;
    printf("Simple Interest : %f",i);
    return 0;
}