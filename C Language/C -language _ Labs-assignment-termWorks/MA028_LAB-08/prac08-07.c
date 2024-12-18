#include <stdio.h>
void fun1();

int main()
{
    printf("Enter a sentence: ");
    fun1();
    return 0;
}
void fun1()
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
    {
        fun1();
        printf("%c", c);
    }
}