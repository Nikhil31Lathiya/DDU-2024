#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE], result[MAX_SIZE];
    int i, j;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            result[j++] = input[i];
        }
    }
    result[j] = '\0';

    printf("String after removing non-alphabetic characters: %s\n", result);

    return 0;
}
