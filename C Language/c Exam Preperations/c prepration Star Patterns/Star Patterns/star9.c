/*

* * * *
 * * *
  * *
   *
  * *
 * * *
* * * * 

*/

#include<stdio.h>
int main()
{
    // first half
    for(int i=0;i<4;i++)
    {
        for(int k=0;k<i;k++)
            printf(" ");
        for(int j=4;j>i;j--)
            printf("* ");
        printf("\n");
    }

    // second half
    for(int i=1;i<=4-1;i++)
    {
        for(int k=4-1;k>i;k--)
            printf(" ");
        for(int j=0;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}