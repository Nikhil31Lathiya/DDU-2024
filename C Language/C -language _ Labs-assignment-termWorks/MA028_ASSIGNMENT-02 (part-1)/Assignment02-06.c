#include<stdio.h>
int main()
{
    int n;
    printf("Enter the Number : ");
    scanf("%d",&n);

    for(int i=n ; i>0 ; i--)
    {
        for(int j=1 ; j<=i ; j++)
        {
            printf( "%d%c",j,(j+64) );
        }
        printf("\n");
    }
return 0;
}