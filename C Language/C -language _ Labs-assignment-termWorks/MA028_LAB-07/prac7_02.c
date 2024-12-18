#include <stdio.h>

int main() {
    int no, d, l = 0;

    printf("Enter a no: ");
    scanf("%d", &no);

    while (no > 0) {
        d = no % 10;
        if (d > l) {
            l = d;
        }
        no /= 10;
    }

    printf("The largest digit is: %d\n", l);

    return 0;
}
