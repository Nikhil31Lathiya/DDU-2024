#include <stdio.h>
#include <math.h>
int count_distinct(int *arr, int n)
{
    int i, j, cnt = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                break;
            }
        }
        if (i == j)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = (M * (int)pow(2, i)) % N;
    }
    printf("%d", count_distinct(arr, N));
    return 0;
}