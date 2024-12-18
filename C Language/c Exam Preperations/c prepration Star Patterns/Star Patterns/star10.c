/*

* * * * *
*       *
*       *
*       *
* * * * *

*/
#include<stdio.h>
int main()
{
    for(int i=0;i<5;i++)
    {
        if (i==0 || i==(5-1))
        {
            for(int j=0;j<5;j++)
                printf("* ");
        }
        else
        {
            for(int j=0;j<5;j++)
            {
                if(j==0 || j==(5-1))
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}