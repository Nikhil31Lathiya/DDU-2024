#include <stdio.h>

int sumOfDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 10) + sumOfDigits(num / 10);
    }
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Sum of digits in %d is: %d\n", number, sumOfDigits(number));

    return 0;
}
