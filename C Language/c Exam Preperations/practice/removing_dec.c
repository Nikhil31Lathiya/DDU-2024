#include<stdio.h>
int main()
{
    int a[] ={4,5,5,5,3,2,7};
    int n=7,temp;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1 ; j<n; j++)
        {
            if(a[i]==a[j])
            {
                for(int k=j ; k<n; k++)
                {
                    a[k] = a[k+1];
                }
                n--;
                j--;
            }
        }
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n ; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nafter this : \n");

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
return 0;
}