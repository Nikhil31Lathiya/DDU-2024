#include <stdio.h>

int s1(int N) {
    int result = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) {
            result -= i * i;
        } else {
            result += i * i;
        }
    }
    return result;
}

double s2(int N) {
    double result = 0.0;
    for (int i = 1; i <= N; ++i) {
        result += 1.0 / (i * i);
    }
    return result;
}

int main() {
    int N;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf(" 1 result: %d\n", s1(N));
   printf(" 2 result: %lf\n", s2(N));

    return 0;
}
