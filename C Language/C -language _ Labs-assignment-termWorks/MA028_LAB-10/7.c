#include <stdio.h>

int main() {
    FILE *file;
    char data[100];

    file = fopen("7.txt", "w");
    if (file == NULL) return 1;

    printf("Enter a string: ");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    fclose(file);

    file = fopen("7.txt", "r");
    if (file == NULL) return 1;

    printf("Read from the file:\n");

    while (fscanf(file, "%c", &data[0]) != EOF) {
        printf("%c", data[0]);
    }

    fclose(file);

    return 0;
}
