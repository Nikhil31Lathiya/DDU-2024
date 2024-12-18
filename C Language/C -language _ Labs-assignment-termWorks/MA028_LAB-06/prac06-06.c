#include <stdio.h>

int main() {
    double M, S, F;

    printf("ENTER THE NUMBER: ");

    scanf("%lf", &M);

    if (M < 0) {
        printf("NEGATIVE VALUE IS NOT A VALID INPUT\n");
        return 0;
    }

    S = M / 2;
    F = S;

    do {
        S = (F + M / F) / 2;
        F = S;
    } while (F - S >= 0.000001);

    printf("%.6lf\n", S);

    return 0;
}
