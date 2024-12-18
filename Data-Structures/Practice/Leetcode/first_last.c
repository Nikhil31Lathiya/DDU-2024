// Find First and Last Position of Element in Sorted Array

#include <stdio.h>

int main()
{
    int nums[] = {1};
    int target = 1;
    int first = -1;
    int last=-1;

    for (int i = 0; i < 1; i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
           
    }
    
    printf("[%d,%d]",first,last);

    return 0;
}
