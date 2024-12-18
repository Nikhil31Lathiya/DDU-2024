#include <stdio.h>
#include <stdlib.h>
void check_triplets(int *nums, int numsSize)
{
    int temp;
    // Sorting the inputed array
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    int sum = 0;

    // Dynamically allocating memory
    int **returnArr;
    returnArr = (int **)malloc(1 * sizeof(int *));
    int count = 0;
    int row_count = 0;
    for (int i = 0; i < numsSize - 2; i++)
    {
        int duplicate = 0;
        for (int j = i + 1; j < numsSize - 1; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
            {
                sum = nums[i] + nums[j] + nums[k];  
                if (sum == 0)
                {
                    if (count == 0)
                    {
                        returnArr[row_count] = (int *)malloc(3 * sizeof(int *));
                        returnArr[row_count][0] = nums[i];
                        returnArr[row_count][1] = nums[j];
                        returnArr[row_count][2] = nums[k];
                        row_count++;
                        count++;
                    }
                    else
                    {
                        // checking for duplicates in rows
                        for (int z = 0; z < count; z++)
                        {
                            if (returnArr[z][0] == nums[i] && returnArr[z][1] == nums[j] && returnArr[z][2] == nums[k])
                            {
                                duplicate = 1;
                                break;
                            }
                        }
                        if (!duplicate)
                        {
                            // Dynamically Recllocating the array
                            returnArr = (int **)realloc(returnArr, (count + 1) * sizeof(int *));
                            returnArr[row_count] = (int *)malloc(3 * sizeof(int *));
                            returnArr[row_count][0] = nums[i];
                            returnArr[row_count][1] = nums[j];
                            returnArr[row_count][2] = nums[k];
                            row_count++;
                            count++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", count);

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", returnArr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int arr[] = {-9, -5, 14, 10, 12, 12, -1, 1, 0};
    int l = sizeof(arr) / sizeof(int);
    check_triplets(arr, l);
    return 0;
}