#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[100], str2[100];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. String Length\n");
        printf("2. String Copy\n");
        printf("3. String Compare\n");
        printf("4. String Concatenation\n");
        printf("5. Convert to Upper Case\n");
        printf("6. Convert to Lower Case\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // STRING LENGTH
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                // STRING COPY
                printf("Enter the source string: ");
                scanf("%s", str1);
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                // STRING COMPARE
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                if (strcmp(str1, str2) == 0) {
                    printf("The strings are equal.\n");
                } else {
                    printf("The strings are not equal.\n");
                }
                break;

            case 4:
                // STRING CONCATENATION
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 5:
                // CONVERT TO UPPER CASE
                printf("Enter a string: ");
                scanf("%s", str1);
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = toupper(str1[i]);
                }
                printf("String in upper case: %s\n", str1);
                break;

            case 6:
                // CONVERT TO LOWER CASE
                printf("Enter a string: ");
                scanf("%s", str1);
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = tolower(str1[i]);
                }
                printf("String in lower case: %s\n", str1);
                break;

            case 0:
                // Exit the program
                printf("End of code\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
