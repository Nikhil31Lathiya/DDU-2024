#include <stdio.h>
int main()
{
    FILE *fptr;
    char ch;
    int count = 0;

    fptr = fopen("example.txt", "r");

    while ((ch = fgetc(fptr)) != EOF)
    {
        printf("%c", ch);
        if (ch == ' ' || ch == '\n')
        {
            count++;
        }
    }
    printf("\n%d\n", count);
    fclose(fptr);
    return 0;
}