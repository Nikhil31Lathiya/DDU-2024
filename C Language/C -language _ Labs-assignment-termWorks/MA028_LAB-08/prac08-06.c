#include <stdio.h>

int powr(int b, int exp) {
    if (exp == 0) {
        return 1;
    } else {
        return b * powr(b, exp - 1);
    }
}

int main() {
    int base, exponent;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    int result = powr(base, exponent);
    printf("%d^%d is: %d\n", base, exponent, result);

    return 0;
}
