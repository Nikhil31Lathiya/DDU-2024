#include <stdio.h>

void reverseDigits(int num);

int main()
{
    int num;
    printf("Enter the Number : ");
    scanf("%d", &num);

    // Function call to reverse the digits
    reverseDigits(num);

    return 0;
}

// Function to reverse the digits using recursion
void reverseDigits(int num)
{
    if (num == 0)
    {
        return;
    }
    else
    {
        printf("%d", num % 10);
        reverseDigits(num / 10);
    }
}
