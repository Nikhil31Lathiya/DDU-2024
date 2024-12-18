// Array insertion
#include <stdio.h>
#include <stdlib.h> // to use malloc function

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
        for(int j=i+1;j<count;j++)
        {
            if(array[i]>array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j]=temp;
            }
        }
    }
}

// Insert new element in the array
void new_insetion(int *array, int *size, int new_val, int pos, int total_cap)
{
    int o_size = *size;
    if (o_size >= total_cap)
    {
        printf("Insertion failed. Array full.");
    }
    else
    {
        // Moving value of every index to next index starting from position of new element 
        for (int i = o_size-1; i >= pos; i--)
        {
            array[i+1]=array[i];
        }

        // Inserting new element at the given position
        array[pos] = new_val;

        // Incrementing the size of the array
        *size = ++o_size;
        printf("Insertion Successfull");

        // Displaying contents of the new array
        printf("\n\nNew Array After Insertion : \n");
        for(int i=0;i<o_size;i++)
        {
            printf("%d\t",array[i]);
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

int main()
{
    int arr[100];
    int size;
    int element, position;

    printf("Enter Size less than or equal 100 : ");
    scanf("%d", &size);

    get_arr(arr, size);
    display(arr, size);

    printf("\n\nEnter Value To Be Inserted : ");
    scanf("%d", &element);
    printf("Enter Position : ");
    scanf("%d", &position);

    new_insetion(arr, &size, element, position, 100);
    printf("\n\nNew size of the array : %d \n",size);
    return 0;
}