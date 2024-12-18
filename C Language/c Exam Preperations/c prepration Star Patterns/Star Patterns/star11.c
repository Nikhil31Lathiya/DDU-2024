/*

    *
   * *
  *   *
 *     *
* * * * *

*/

#include<stdio.h> 
int main()
{
    for(int i=0;i<5;i++)
    {
        if(i==4)
        {
            for(int j=0;j<5;j++)
                printf("* ");
        }
        else
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
        }
        printf("\n");
    }
    return 0;
}