#include <stdio.h>

// Get elements of array
void get_arr(int *array, int count) // Address of the array passed to the funtion
{
    printf("\nEnter elements of array : \n");
    int temp;
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
    }

    // Array Sorting -> Bubble Sort
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Display all array elements
void display(int array[], int count) // Copy of the array passed to the function
{
    printf("\nArray elements are : \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t", array[i]);
    }
}

// Delete element at a particular index
void ele_deletion(int arr[], int *size, int index, int capacity)
{
    int o_size = *size;
    if (index > capacity)
    {
        printf("ERROR!!! Index out of bound");
    }
    else
    { 
        // Traversion indices to total size - 1
        for (int i = index; i < o_size; i++)
        {
            arr[i] = arr[i + 1];
        }
        *size = --o_size;
    }
}

int main()
{
    int arr[100];
    int size;
    int ind_position ;

    printf("Enter Size less than or equal 100 : ");
    scanf("%d", &size);

    get_arr(arr, size);
    display(arr, size);

    printf("\nEnter Position : ");
    scanf("%d", &ind_position);

    ele_deletion(arr, &size, ind_position, 100);
    display(arr,size);

    printf("\n\nNew size of the array : %d \n", size);
    return 0;
}