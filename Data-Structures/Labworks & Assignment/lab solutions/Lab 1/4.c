#include<stdio.h>
int main()
{
    int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int *p;
    p=arr;

    printf("Address : %d",p);
    for(int i = 0; i<15 ;i++)
        printf("%d  ",*(p+i));
    return 0;
}