#include <stdio.h>
int main( ) {
int x = 3,y = 5,z = 7,w;
w = x % y + y % x - z % x - x % z;
printf("%d \n", w);
w = x / z + y / z + (x + y) / z;
printf("%d\n", w);
w = x / z * y / z + x * y / z;
printf("%d\n", w);
w = x % y % z + z % y % (y % x);
printf("%d\n", w);
w = z / y / y / x + z / y / (y / x);
printf("%d\n", w);
return 0;
}