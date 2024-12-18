#include <stdio.h>
int searchInsert(int *nums, int numsSize, int target)
{
    int temp;
    int i ,j;
    // Sorting the array
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    // Checking the target in array
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }

    for(i=0;i<numsSize;i++)
    {
        if(target<=nums[i])
        {
            printf("%d",target);
            return i;
        }

    }
    return i;
}
int main()
{
    int nums[] = {1, 3, 5, 6};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int b = searchInsert(nums, numsSize, target);
    printf("Index -> %d", b);
    return 0;
}