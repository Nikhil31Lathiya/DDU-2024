#include <stdio.h>

int main()
{
    char str[100];
    int cl = 1, ml = 1, i;

    scanf("%s", str);
    for (i = 1; str[i] != '\0'; ++i)
    {
        if (str[i] == str[i - 1])
        {
            cl++;
        }
        else
        {
            cl = 1;
        }
        if (cl > ml)
        {
            ml = cl;
        }
    }
    printf("%d", ml);
    return 0;
}
