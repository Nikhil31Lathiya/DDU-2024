#include<stdio.h>
int main()
{
 int arr[1000];
 int n , count = 0 , nc=0;

 printf("Enter the size of an array \n");
 scanf("%d", &n);
printf("Enter the elements : \n");

 for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
 }

    for(int i = 0; i < n; i++)
    {
        for(int j=i+1 ; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
              for(int k=j ; k < n; k++)
              {
                arr[k] = arr[k+1];
              }
              n--;
              j--;  
              count++;    
            }
        }
    }
    printf("\n the array is : ");
    for(int i = 0; i < n; i++)
    {
    printf(" %d ", arr[i]);
    }
       printf("\nand duplicate value is : %d " , count);  
return 0;
}