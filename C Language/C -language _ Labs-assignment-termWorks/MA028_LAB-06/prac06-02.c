#include <stdio.h>

int main() {
    char choice;
    double num1, num2, result;

    do {
        printf("Enter the first no: ");
        scanf("%lf", &num1);
        printf("Enter the second no: ");
        scanf("%lf", &num2);

        printf("Select an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("Enter the operation number: ");
        int operation;
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                if (num2 != 0) 
                {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                } else 
                {
                    printf("Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid operation number.\n");
        }

        printf("Do you want to perform another operation? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
