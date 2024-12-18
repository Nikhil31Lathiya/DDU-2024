#include <stdio.h>
int main()
{
    char s1[10] = "hello";
    char *p_s1, *p_s2, *p_s3, *p_s4;
    p_s1 = s1;

    char s2[10];
    p_s2 = s2;

    char s3[10] = "World";
    p_s3 = s3;

    char s4[10] = "hello";

    // Copy one string to another
    while (*p_s1 != '\0')
    {
        *p_s2 = *p_s1;
        p_s1++;
        p_s2++;
    }
    int i = 0;
    while (s2[i] != '\0')
    {
        printf("%c", s2[i]);
        i++;
    }
    i = 0;
    // Concatenate 2 strings
    while (*p_s1 != '\0')
    {
        p_s1++;
    }
    while (*p_s3 != '\0')
    {
        *p_s1 = *p_s3;
        p_s3++;
        p_s1++;
    }
    *p_s1 = '\0';
    printf("\nConcatenated string: %s\n", s1);

    // Compare 2 Strings
    p_s2 = s2;
    p_s4 = s4;
    while (*p_s2 == *p_s4)
    {
        if (*p_s2 == '\0' && *p_s4 == '\0')
        {
            break;
        }
        p_s2++;
        p_s4++;
    }

    if (*p_s2 == '\0' && *p_s4 == '\0')
    {
        printf("\n\nBoth Strings Are Equal");
    }
    else
    {
        printf("\n\nBoth Strings Are Not Equal");
    }

    return 0;
}