#include <stdio.h>
int main(){
int x, y, z;
x = 2 + 3 - 4 + 5 - (6 - 7);
y = 2 * 33 + 4 * (5 - 6);
z = 2 * 3 * 4 / 15 % 13;
x = 2 * 3 * 4 / (15 % 13);
y = 2 * 3 * (4 / 15 % 13);
z = 2 + 33 % 5 / 4;
x = 2 + 33 % - 5 /4;
y = 2 - 33 % - 5 /- 4;
z =-2*-3/-4%-5;
x =50 % (5 * (16 % 12 * (17/3)));
y=-2*-3%-4 /-5-6+-7;
z = 8 /4 / 2*2*4*8 %13 % 7 % 3;
printf("x=%d \t y=%d \t z=%d\n",x,y,z);
return 0;
}