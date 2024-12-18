/*
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include<stdio.h>
int main()
{
    // First Half
    for(int i=0;i<5;i++)
    {
        for(int k=1;k<5-i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<=2*i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    // Second Half
    for(int i=0;i<5;i++)
    {
        for(int k=0;k<i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<(2*(5-i))-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}