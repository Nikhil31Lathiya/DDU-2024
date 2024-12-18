#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int *p[5];

    for(int i=0;i<5;i++)
        p[i]=&arr[i];

    for(int i=0;i<5;i++)
        printf("Value : %d , Address : %d\n",*p[i],p[i]);

    return 0;
}