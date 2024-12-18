// Implementing Array Data Structure
// Collecting elements of array from the user


#include <stdio.h>
#include <stdlib.h> // to use malloc function
struct array1
{
    int total_size;
    int used_size;
    int *ptr;
};

// create array
void create_arr(struct array1 *a, int t_size, int u_size)
{
    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int)); // dynamic memory allocation for array of size total_size or t_size passed as arguement in the function
}

// Set values in the array
void set_arr(struct array1 *a)
{
    printf("\nEnter Elements : \n");
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d", &(a->ptr)[i]); // Inputting values for array elements
    }
}

// Display all elements of the array
void show(struct array1 *a)
{
    printf("\nArray Elements Are : \n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    int tSize, uSize;
    printf("Enter total size of the array : ");
    scanf("%d", &tSize);
    printf("Enter size of the array to be used : ");
    scanf("%d", &uSize);
    struct array1 marks;
    create_arr(&marks, tSize, uSize);
    set_arr(&marks);
    show(&marks);
    return 0;
}