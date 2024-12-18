#include<stdio.h>
int main()
{
    int a[100] , i, size , max , temp, x;

    printf("Enter the size of array : \n");
    scanf("%d", &size);
    printf("Enter value in array : \n");

    for(int i=0 ; i<size ; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(i=0 ; i<size ; i++)
    {
        for(int j=i+1 ; j<size ; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf(" min term is  %d ", a[0] );
    printf(" max term is  %d ", a[size-1] );

return 0;
}
