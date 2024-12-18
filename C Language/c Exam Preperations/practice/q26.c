#include<stdio.h>
int main()
{
    int n=5;
    int t=1 , sum ;

    printf("no of terms : ");

    for(int i=1 ; i<=n ; i++)
    {
        printf("%d + ", t);
    sum= sum+t;
    t= t*10+1;
    }
    printf("\nsum is : %d  ", sum );
return 0;
}