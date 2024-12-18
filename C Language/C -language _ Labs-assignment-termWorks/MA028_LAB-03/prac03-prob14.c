#include <stdio.h>
int main()
{
double pi = 3.14159265;
printf("%15f\n", pi);
printf("%15.12f\n", pi);
printf("%-15.12f\n", pi);
printf("%15.4f\n", pi);
printf("%15.0f\n", pi);
printf("%15.3g\n", pi);
printf("%15g\n", pi);
printf("%15.4e\n", pi);
printf("%15e\n", pi);
return 0;
}