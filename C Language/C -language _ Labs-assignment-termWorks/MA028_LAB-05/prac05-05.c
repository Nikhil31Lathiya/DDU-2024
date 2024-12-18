#include <stdio.h>

int main() {
    float s1, s2, s3;

    printf("Enter the value of the first side: ");
    scanf("%f", &s1);
    printf("Enter the value of the second side: ");
    scanf("%f", &s2);
    printf("Enter the value of the third side: ");
    scanf("%f", &s3);

    if (s1 + s2 + s3 == 180 && s1 > 0 && s2 > 0 && s3 > 0) {
        printf("triangle can be formed.\n");
    } else {
        printf("triangle cannot be formed.\n");
    }

    return 0;
}
