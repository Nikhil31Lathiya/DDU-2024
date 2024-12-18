#include <stdio.h>

int main() {
    double s1, s2, s3;
    char choice;

    while (1) 
    {
        printf("Enter the s of  triangle:\n");
        scanf("%lf %lf %lf", &s1, &s2, &s3);

        if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) 
        {
            if (s1 == s2 && s2 == s3) 
            {
                printf("It's an equilateral triangle.\n");
            } 
            else if (s1 == s2  || s2 == s3 || s1 == s3) 
            {
                printf("It's an isosceles triangle.\n");
            } 
            else
            {
                printf("It's a scalene triangle.\n");
            }
            break;
        } 
        else
        {
            printf("A triangle cannot be formed \n");
            printf(" re-enter s lengths? (Y/N): ");
            scanf(" %c", &choice);
            if (choice != 'Y' && choice != 'y') 
            {
                break; 
            }
        }
    }

    return 0;
}
