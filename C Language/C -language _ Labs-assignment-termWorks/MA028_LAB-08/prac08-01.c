#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0) 
        return 0;
    return 1;
}

int isArmstrong(int num) {
    int originalNum = num, n = 0, result = 0;
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;
    while (originalNum != 0) {
        result += pow(originalNum % 10, n);
        originalNum /= 10;
    }

    return result == num;
}

int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i <= num / 2; ++i)
        if (num % i == 0) sum += i;
    return sum == num;
}

int main() {
    int start, end;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; ++i)
        if (isPrime(i)) printf("%d ", i);

    printf("\nArmstrong numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; ++i)
        if (isArmstrong(i)) printf("%d ", i);

    printf("\nPerfect numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; ++i)
        if (isPerfect(i)) printf("%d ", i);

    return 0;
}
