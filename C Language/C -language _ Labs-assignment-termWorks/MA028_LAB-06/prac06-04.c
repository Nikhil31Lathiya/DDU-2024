#include <stdio.h>

int main() {
    int width, precision;
    double number = 123.456789;

    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter precision: ");
    scanf("%d", &precision);

    printf("Formatted output with field width and precision:\n");
    printf("%*.*lf\n", width, precision, number);

    return 0;
}
