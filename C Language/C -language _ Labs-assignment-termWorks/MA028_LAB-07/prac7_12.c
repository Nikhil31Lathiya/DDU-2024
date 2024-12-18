#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int i, alphabets = 0, digits = 0, specials = -1, vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            alphabets++;
            if (tolower(input[i]) == 'a' || tolower(input[i]) == 'e' ||
                tolower(input[i]) == 'i' || tolower(input[i]) == 'o' ||
                tolower(input[i]) == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(input[i])) {
            digits++;
        } else {
            specials++;
        }
    }

    printf("Total Alphabets: %d\n", alphabets);
    printf("Total Digits: %d\n", digits);
    printf("Total Special Characters: %d\n", specials);
    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);

    return 0;
}
