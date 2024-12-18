#include <stdio.h>

int main() {
    char choice;
    char ch,ch_user;

    do {
        printf("Enter a ch: ");
        scanf(" %c", &ch);


        if (ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U' || ch == 'a' || 
            ch == 'e' || ch == 'i' || ch == 'o' || 
            ch == 'u') 
        {
            printf("%c is a vowel.\n", ch);
        } else {
            printf("%c is consonent.\n", ch);
        }

        printf("check another ch? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
