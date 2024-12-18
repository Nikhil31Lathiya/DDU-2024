#include<stdio.h>
int main()
{
    int a=1 ,n=50, sum=0;

    for(int i=a ; i<n ; i++)
    {
        if(n%i==0 )
        {

            if(sum==n)
             {
                printf("%d ", sum);
             }
        }
    }
    
   
return 0;
}