#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *uf, *sf;
    int n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    uf = fopen("Unsort.txt", "w");
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        fprintf(uf, "%d\n", arr[i]);
    }
    fclose(uf);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    sf = fopen("Sort.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(sf, "%d\n", arr[i]);
    }
    fclose(sf);

    printf("\nContents of Unsort.txt:\n");
    uf = fopen("Unsort.txt", "r");
    while (fscanf(uf, "%d", &arr[n]) != EOF) {
        printf("%d\n", arr[n]);
    }
    fclose(uf);

    printf("\nContents of Sort.txt:\n");
    sf = fopen("Sort.txt", "r");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    fclose(sf);

    free(arr);

    return 0;
}
