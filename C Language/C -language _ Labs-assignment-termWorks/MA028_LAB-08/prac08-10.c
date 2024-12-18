#include <stdio.h>

int countDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return 1 + countDigits(num / 10);
    }
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Number of digits in %d is: %d\n", number, countDigits(number));

    return 0;
}
