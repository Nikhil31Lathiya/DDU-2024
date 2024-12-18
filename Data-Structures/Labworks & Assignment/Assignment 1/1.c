#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N;
    int **arr1, **arr2, **result;
    
    arr1 = (int **) malloc(N*sizeof(int *));
    arr2 = (int **) malloc(N*sizeof(int *));
    result = (int **) malloc(N*sizeof(int *));
    printf("Enter Size of Matrix : ");
    scanf("%d",&N);

    printf("Enter elements of array 1 : ");

    for (int i = 0; i < N; i++)
    {
        arr1[i] = (int *)malloc(N*sizeof(int *));
        for (int  j = 0; j < N; j++)
        {
            scanf("%d",&arr1[i][j]);    
        }
    }

    printf("Enter elements of array 2 : ");
    
    for (int i = 0; i < N; i++)
    {
        arr2[i] = (int *)malloc(N*sizeof(int *));
        for (int  j = 0; j < N; j++)
        {
            scanf("%d",&arr2[i][j]);              
        }
    }
    
    for(int i=0;i<N;i++)
    {
        result[i] = (int *)malloc(N*sizeof(int *));
        for(int j=0;j<N;j++)
        {
            result[i][j] = arr1[i][j]+arr2[i][j];
            printf("%d",result[i][j]);
        }
        printf("\n");
    }
    return 0;
} 

/*
1   2
3   4

5   6
7   8
*/