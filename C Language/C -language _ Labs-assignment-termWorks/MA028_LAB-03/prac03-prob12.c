#include <stdio.h>
int main(){
int x = 3, y = 5, z = 7, w = 9;
w += x;
printf("w = %d\n", w);
w -= y;
printf("w = %d\n", w);
x *= z;
printf("x = %d\n", x);
w += x + y - (z -= w);
printf("w = %d, z = %d\n", w, z);
w += x -= y %= z;
printf("w = %d, x = %d, y = %d\n",w, x, y);
w *= x / (y += (z += y));
printf("w = %d, y = %d, z = %d\n",w, y, z);
w /= 2 + (w %= (x += y - (z -= -w)));
printf("w = %d, x = %d, z = %d\n",
w, x, z);
return 0;
}