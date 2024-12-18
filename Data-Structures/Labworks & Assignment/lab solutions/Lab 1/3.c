#include<stdio.h>
int main()
{
    int n = 10;
    int *p = &n;
    int **q = &p;

    printf("Number Variable Value : %d, Address : %d.\n",n,&n);
    printf("Pointer Variable Value : %d, Address : %d.\n",p,&p);
    printf("Pointer-to-Pointer Variable Value : %d, Address : %d.",q,&q);
    return 0;
} 