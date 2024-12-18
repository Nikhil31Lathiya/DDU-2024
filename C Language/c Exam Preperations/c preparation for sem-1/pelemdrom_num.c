#include <stdio.h>
void func(int arg)
{
    int original_numbers = arg;
    int reverse = 0;

    while (arg > 0)
    {
        int digit = arg % 10;
        reverse = reverse * 10 + digit;
        arg = arg / 10;
    }
    if (original_numbers == reverse)
    {
        printf("pelindrom");
    }
    else
    {
        printf("pelindrom not");
    }
}
int main()
{
    int i;
    printf("Enter number:");
    scanf("%d", &i);

    func(i);
    return 0;
}
