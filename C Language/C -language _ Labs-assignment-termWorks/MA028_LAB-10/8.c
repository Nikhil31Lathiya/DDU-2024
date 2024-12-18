#include <stdio.h>

int main() {
    FILE *file, *oddFile, *evenFile;
    int N, num;

    printf("Enter the number of integers: ");
    scanf("%d", &N);

    file = fopen("OddEven.txt", "w");
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    fclose(file);

    file = fopen("OddEven.txt", "r");
    oddFile = fopen("Odd.txt", "w");
    evenFile = fopen("Even.txt", "w");

    while (fscanf(file, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            fprintf(evenFile, "%d\n", num);
        } else {
            fprintf(oddFile, "%d\n", num);
        }
    }

    fclose(file);
    fclose(oddFile);
    fclose(evenFile);

    printf("\nContents of OddEven.txt:\n");
    file = fopen("OddEven.txt", "r");
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    fclose(file);

    printf("\nContents of Odd.txt:\n");
    oddFile = fopen("Odd.txt", "r");
    while (fscanf(oddFile, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    fclose(oddFile);

    printf("\nContents of Even.txt:\n");
    evenFile = fopen("Even.txt", "r");
    while (fscanf(evenFile, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    fclose(evenFile);

    return 0;
}
