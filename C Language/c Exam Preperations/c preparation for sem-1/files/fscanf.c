#include <stdio.h>
int main()
{
    int age;
    char name[30];

    FILE *fptr;

    fptr = fopen("example.txt", "r+");

    if (fptr == NULL)
    {
        printf("Couldn't open");
        return 1;
    }

    fscanf(fptr, "%s  %d", name, &age);

    printf("\n %s ", name);
    printf("\n %d\n", age);

    fprintf(fptr, "abhishek");
    fclose(fptr);
    return 0;
}