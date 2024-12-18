#include <stdio.h>
int main()
{
    int size;
    printf("Enter Array size of integers: ");
    scanf("%d", &size);

    int a[size], i, j, temp;

    printf("Enter size integers: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Array size integers: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}