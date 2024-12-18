#include <stdio.h>
#include <stdlib.h>
// easy code done by me
// int temp;
// printf("[");
// for(int i=0;i<numsSize;i++)
// {
//     for(int j=i+1;j<numsSize;j++)
//     {
//         for(int k=j+1;k<numsSize;k++)
//         {
//             if(nums[i]+nums[j]+nums[k]==0)
//             {
//                 printf("[%d,%d,%d]",nums[i],nums[j],nums[k]);
//             }
//             temp = k;
//         }
//     }
//     i = temp;
// }
// printf("]");
// *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize * numsSize);
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize * numsSize);
    int **returnArr = (int **)malloc(sizeof(int *) * numsSize * numsSize * numsSize);
    *returnSize = 0;
    int r_a_size = 0;
    int *arr = (int *)malloc(sizeof(int) * 3); // dynamic array for swaping purpose
    // 3 nested loops to check triplets
    for (int i = 0; i < numsSize; i++)
    {
        int skip_dup = 0;
        for (int j = i + 1; j < numsSize; j++)
        {
            // printf("%d\n", i);?
            // arr = NULL;
            for (int k = j + 1; k < numsSize; k++)
            {
                // checking if sum of triplets = 0
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    // printf("i-> %d  j-> %d  k->%d\t\t", i, j, k);
                    // printf("value i-> %d  value j-> %d  value k->%d\n", nums[i], nums[j], nums[k]);

                    int t;
                    arr[0] = nums[i];
                    arr[1] = nums[j];
                    arr[2] = nums[k];
                    for (int x = 0; x < 3; x++)
                    {
                        for (int y = x + 1; y < 3; y++)
                        {
                            if (arr[x] > arr[y])
                            {
                                t = arr[x];
                                arr[x] = arr[y];
                                arr[y] = t;
                            }
                        }
                    }
                    returnArr[*returnSize] = (int *)malloc(sizeof(int) * 3);
                    for (int x = 0; x < 3; x++)
                    {
                        if (r_a_size == 0)
                        {
                            returnArr[*returnSize][x] = arr[x];
                            // printf("%d -> %d\n", r_a_size, returnArr[*returnSize][x]);
                            r_a_size += 1;
                        }
                        else
                        {
                            for (int u = 0; u < r_a_size; u++)
                            {
                                if (arr[0] == returnArr[u][0])
                                {
                                    printf("Duplicate found\n");
                                    break;
                                }
                                else
                                {
                                    returnArr[*returnSize][x] = arr[x];
                                    printf("%d -> %d\n", r_a_size, returnArr[*returnSize][x]);
                                    r_a_size += 1;
                                }
                            }
                        }
                        returnArr[*returnSize][x] = arr[x];

                        // printf("%d\t", returnArr[*returnSize][x]);
                    }
                    printf("\n");
                    // skip_dup = k + 1;
                    // break;
                }
            }
        }
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            printf("%d\n", returnArr[i][j]);
        }
    }
     return returnArr;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    return 0;
}