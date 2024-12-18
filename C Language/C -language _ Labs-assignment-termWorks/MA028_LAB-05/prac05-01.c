#include <stdio.h>

int main() {
    
    float unit;
    float amt = 0;

    printf("Enter The number in units : ");
    scanf("%f", &unit);

    if (unit <= 100) 
    {
        amt = unit * 0.75;
    }
     else if (unit <= 300) 
     {
        amt = 100 + (unit - 100) * 1.00;
     } 
     else if (unit <= 500) 
     {
        amt = 300+ (unit - 300) * 1.50;
     } 
     else 
     {
        amt = 500+ (unit - 500) * 1.75;
    }

    printf("amount to be paid: Rs. %f\n", amt);

    return 0;
}
