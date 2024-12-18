#include<stdio.h>

int main()
{
    // int x = 2;
    // int y = -2;

    // int point[2];
    // point[0] = 2;
    // point[1] = -2;

    // printf("x = %d y = %d\n",x,y);
    // printf("x = %d y = %d\n",point[0],point[1]);

    // int arr[] = {1,2,3,4,5,6,7,8,9};
    // double arr[20] = {1,2,3,4,5,6,7,8,9};
    // for(int i=0;i<9;i++)
    //     printf("[%d]=%d ",i,arr[i]);
    // printf("\n");

    // int arr1[9];
    // for(int i=0;i<9;i++)
    //     arr1[i] = i+1;
    // for(int i=0;i<30;i++)
    //     printf("[%d]=%d ",i,arr1[i]);
    // printf("\n");

    // printf("%d %d\n",arr,arr1);
    // printf("[0]=%d [1]=%d\n",&arr[0],&arr[1]);
    // printf("[-1]=%d [0]=%d\n",&arr[-1],&arr[0]);
    // printf("[0]=%d [1]=%d [4]=%d \n",&arr[0],arr+1,arr+4);
    
    
    
    // double arr[]= {1,2,3,4,5,6,7,8,9,10,11,12};
    // double arr1[12];
    // for(int i=0;i<10;i++){
    //     printf("[%d]=%.2f ",i,arr[i]*=2);
    //     arr1[i] = arr[i];
    // }
    
    // printf("\n");

    // for(int i=0;i<10;i++){
    //     printf("[%d]=%.2f ",i,arr1[i]*=2);
    // }
    int s = 5;
    scanf("%d",&s);
    int arr[s];
    for(int i =0;i<s;i++)
        scanf("%d",arr+i);
    for(int i =0;i<s;i++)
        printf("%d ",i[arr]);
    printf("\n");
    return 0;
}