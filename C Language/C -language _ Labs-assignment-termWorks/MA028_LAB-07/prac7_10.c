#include <stdio.h>

int main() {
    int o;
    int m1[100][100], m2[100][100], result[100][100];

    printf("Enter the o of the square matrices: ");
    scanf("%d", &o);

    printf("Enter elements for Matrix 1:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter elements for Matrix 2:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m2[i][j]);
        }
    }

    printf("\nOriginal Matrix 1:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d\t", m1[i][j]);
        }
        printf("\n");
    }

    printf("\nOriginal Matrix 2:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d\t", m2[i][j]);
        }
        printf("\n");
    }

    // Transpose of both matrices
    for (int i = 0; i < o; i++) {
        for (int j = i + 1; j < o; j++) {
            // Swap elements across the main diagonal
            int temp = m1[i][j];
            m1[i][j] = m1[j][i];
            m1[j][i] = temp;

            temp = m2[i][j];
            m2[i][j] = m2[j][i];
            m2[j][i] = temp;
        }
    }

    // Display transposed matrices
    printf("\nTranspose of Matrix 1:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d\t", m1[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of Matrix 2:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d\t", m2[i][j]);
        }
        printf("\n");
    }

    // Addition of matrices
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Display the sum matrix
    printf("\nSum of Matrices:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    // Subtraction of matrices
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    // Display the difference matrix
    printf("\nDifference of Matrices:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
