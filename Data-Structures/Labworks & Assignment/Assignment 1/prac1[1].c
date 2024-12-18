#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    // Allocate memory for the 3D array
    int *matrices = (int *)malloc(3 * n * n * sizeof(int));
    if (!matrices)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the matrices from the user
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", matrices + i * n + j);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", matrices + n * n + i * n + j);
        }
    }

    // Add the matrices
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(matrices + 2 * n * n + i * n + j) = *(matrices + i * n + j) + *(matrices + n * n + i * n + j);
        }
    }

    // Print the result
    printf("The sum of the matrices is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(matrices + 2 * n * n + i * n + j));
        }
        printf("\n");
    }

    // Free the memory
    free(matrices);

    return 0;
}