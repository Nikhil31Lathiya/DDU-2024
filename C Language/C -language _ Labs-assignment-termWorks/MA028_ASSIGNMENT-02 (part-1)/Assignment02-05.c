#include<stdio.h>
int main()
{
 int arr[1000];
 int n , count = 0 , nc=0;

 printf("Enter the inputs to be entered \n");
 scanf("%d", &n);

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
            }
        }
    }

    printf("\n The ans is : %d", n);

return 0;
}