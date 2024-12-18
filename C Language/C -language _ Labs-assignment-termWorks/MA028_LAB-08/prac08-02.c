#include <stdio.h>

int main() {
    int decimalNumber;

    printf("Enter an integer in decimal format: ");
    scanf("%d", &decimalNumber);

    printf("Hexadecimal: %X\n", decimalNumber);
    printf("Octal: %o\n", decimalNumber);

    printf("Binary: ");
    int binary[32];  
    int i = 0;
    while (decimalNumber > 0) {
        binary[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}
