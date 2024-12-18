#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *base, *last;
    int temp;

    base = &arr[0];
    last = &arr[4];
    while (base < last)
    {
        temp = *base;
        *base = *last;
        *last = *(&temp);

        base++;
        last--;

    }

    printf("Reversed Array : \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}