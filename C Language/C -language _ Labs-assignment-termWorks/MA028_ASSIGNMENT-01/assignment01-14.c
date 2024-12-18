#include<stdio.h>
int main()
{
    int rows;
    scanf("%d",&rows);
    for (int i=1;i<=rows;i++)
    {
        for (int s=0; s<i;s++)
        {
            printf(" ");
        }
        for(int j=i;j<=rows;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }

    for (int i = rows; i > 0; i--)
    {
        for(int s=0;s<i;s++)
        {
            printf(" ");
        }
        for (int j = i; j<=rows; j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    
}