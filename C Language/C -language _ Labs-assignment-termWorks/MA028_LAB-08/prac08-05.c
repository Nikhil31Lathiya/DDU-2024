#include <stdio.h>

double feetToInches(double feet) {
    return feet * 12.0;
}

double inchesToCentimeters(double inches) {
    return inches * 2.54;
}

double centimetersToMeters(double centimeters) {
    return centimeters / 100.0;
}

int main() {
    double feet;

    printf("Enter measurement in feet: ");
    scanf("%lf", &feet);

    double inches = feetToInches(feet);
    printf("%.2lf feet is equal to %.2lf inches.\n", feet, inches);

    double centimeters = inchesToCentimeters(inches);
    printf("%.2lf inches is equal to %.2lf centimeters.\n", inches, centimeters);

    double meters = centimetersToMeters(centimeters);
    printf("%.2lf centimeters is equal to %.2lf meters.\n", centimeters, meters);

    return 0;
}
