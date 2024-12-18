#include <stdio.h>
int main()
{
    FILE *main, *o, *e;
    int c;
    int m;
    printf("Enter the max  numbers  : ");
    scanf("%d", &m);
    int n[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &n[i]);
    }

    main = fopen("oddeven.txt", "a+");

    for (int i = 0; i < m; i++)
    {
        fprintf(main, "%d ", n[i]);
    }

    while (c = fgetc(main) != EOF)
    {
        if (c % 2 == 0)
        {
            e = fopen("even.txt", "a");
            fprintf(e, "%d ", c);
        }
        }
    return 0;
}