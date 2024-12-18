#include<stdio.h>
int main()
{
int x = 7, y = -7, z = 11,
w =- 11, s = 9, t = 10;
x += (y -= (z *= (w /= (s %= t))));
printf("x = %d, y = %d, z = %d, w= %d,s = %d, t = %d\n", x, y, z, w, s, t);
t += s -= w *= z *= y %= x;
printf("x = %d, y %d, z = %d, w =%d,s = %d, t = %d\n", x, y, z, w, s, t);
return 0;
}