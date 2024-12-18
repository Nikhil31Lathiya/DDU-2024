#include <stdio.h>
int main()
{
    int a[] = {4, 5, 5, 5, 3, 5, 6, 5, 3, 2, 7};
    int n = 11, temp, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < n; k++)
                {
                    a[k] = a[k + 1];
                }
                n--;
                j--;
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nafter this : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n %d ", cnt);
    return 0;
}