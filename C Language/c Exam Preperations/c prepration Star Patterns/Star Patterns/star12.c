/*

* * * * *
 *     *
  *   *
   * *
    *  

*/
#include<stdio.h> 
int main()
{
    for (int i=0;i<5;i++)
    {
        if(i==0)
        {
            for(int j=0;j<5;j++)
                printf("* ");
        }
        else
        {
            for(int k=0;k<i;k++)
                printf(" ");
            for(int j=5;j>i;j--)
            {
                if(j==5 || j==i+1)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}