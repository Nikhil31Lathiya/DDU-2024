#include <stdio.h>
int main ()
{
    int no;

    printf("Enter the no : ");    
    scanf("%d",&no);
    
    for(int i=1;i<=no;i++)
    {
        for (int j =1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}