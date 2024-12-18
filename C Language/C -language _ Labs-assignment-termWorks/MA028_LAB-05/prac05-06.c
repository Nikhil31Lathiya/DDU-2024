#include <stdio.h>

int main() {
    int month,year,days;

    printf("Enter the month number : ");
    scanf("%d", &month);

    if (month < 1 || month > 12) 
    {
        printf("Invalid month number.\n");
    } 
    else 
    {
        if (month == 2) {
            printf("Enter the year (e.g. 2007): ");
            scanf("%d", &year);

            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days = 29;
            } else 
            {
                days = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days = 30;
        } else 
        {
            days = 31;
        }

        printf("The month has %d days.\n", days);
    }

    return 0;
}
