#include<stdio.h>
int main()
{
   int a[100], n, temp;

    printf("Enter The size of arry :  ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Element no : %d\n",i);
        scanf("%d", &a[i]);
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
        printf("Shorted array : \n");

    for(int i = 0; i < n; i++)
    {
       printf("%d \n",a[i]);
    }
return 0;
}