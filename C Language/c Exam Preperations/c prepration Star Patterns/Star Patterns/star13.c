/*

    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    * 

*/

#include<stdio.h>
int main()
{
    // first half
    for(int i=0;i<5;i++)
    {
        for(int k=1;k<5-i;k++)
            printf(" ");
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    // second half
    for(int i=1;i<5;i++)
    {
        for(int k=0;k<i;k++)
            printf(" ");
        for(int j=4;j>=i;j--)
        {
            if(j==4 || j==i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}