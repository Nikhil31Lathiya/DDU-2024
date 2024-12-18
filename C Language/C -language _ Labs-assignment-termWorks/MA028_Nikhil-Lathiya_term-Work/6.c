#include <stdio.h>

int main()
{
    int N;

    printf("Enter the size of the matrix (N): ");
    scanf("%d", &N);

    int isUpperTriangular = 1;
    int isLowerTriangular = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int num;
            scanf("%d", &num);

            // Check upper triangular condition
            if (i > j && num != 0)
            {
                isUpperTriangular = 0;
            }

            // Check lower triangular condition
            if (i < j && num != 0)
            {
                isLowerTriangular = 0;
            }
        }
    }

    if (isUpperTriangular || isLowerTriangular)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
