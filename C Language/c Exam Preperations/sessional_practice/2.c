#include <stdio.h>
#include <conio.h>

int main()
{

    int i, j;

    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= 33; j++)
        {
            if (j < 4)
            {
                if (j == 0 || j == 3 || i == 2) // this if part is describe the H
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            else if (j < 9 && j > 4)
            {
                if (j == 5 || j == 8)
                {
                    printf("* ");
                }
                else if (i == 0 || i == 2)
                {
                    if (j <= 8 && j >= 5) // this part is describe as a A
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                else
                {
                    printf("  ");
                }
            }

            else if (j > 9 && j < 14)
            {
                if (j == 10)
                {
                    printf("* ");
                }
                else if (j == 13 && i < 3)
                {
                    printf("*");
                }
                else if (i == 0 || i == 2) /// this is capital R
                {
                    if (j <= 13 && j >= 10)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                else if (i - j == -9)
                {
                    printf("* ");
                    if (i == 3 && j == 12)
                    {
                        printf(" ");
                    }
                }

                else
                {
                    printf("  ");
                }
            }
            else if (j > 14 && j < 19)
            { // this part describe S
                if (j == 15 && i < 3)
                {
                    printf(" * "); // first right side of s
                }
                else if (i == 0 || i == 2 || i == 4)
                {
                    printf("* ");
                }
                else if (i >= 2 && j == 18)
                { // second side of the  s it means left
                    printf("*");
                }
                else
                {
                    printf("  ");
                }
            }

            else if (j > 19 && j < 24)
            {
                if (j == 20 || j == 23 || i == 2)
                { // this part is describe as a H
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }

            else if (j < 29 && j > 24)
            {
                if (j == 25 || j == 28)
                {
                    printf("* ");
                }
                else if (i == 0 || i == 2) ////this part is A
                {
                    printf("* ");
                }

                else
                {
                    printf("  ");
                }
            }

            // this is l

            else if (j > 29 && j <= 33)
            {
                if (j == 30 || i == 4)
                {
                    printf("* ");
                }
            }

            else
            {
                printf("");
            }
        }
        printf("\n");
    }
    return 0;
}