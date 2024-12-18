#include <stdio.h>

int main() {
    int n, ft = 0, st = 1, nt;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms: \n", n);

    for (int i = 0; i < n; i++)
     {
        if (i <= 1)
         {
            nt = i;
         } else 
        {
            nt = ft + st;
            ft = st;
            st = nt;
        }
        printf("%d  ", nt);
    }

    return 0;
}
