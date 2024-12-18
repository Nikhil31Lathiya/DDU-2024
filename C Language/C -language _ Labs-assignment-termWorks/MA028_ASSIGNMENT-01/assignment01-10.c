#include <stdio.h>

int main() {
    int row;
    scanf("%d", &row);

    for (int i = 1; i <= row; i++) {
        for(int s=0;s<=row-i;s++)
            printf(" ");
        for (int j = i; j <= 2 * i - 1; j++) {
            printf("%d", j);
        }

        for (int k = 2 * i - 2; k >= i; k--) {
            printf("%d", k);
        }

        printf("\n");
    }

    return 0;
}
