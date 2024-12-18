#include <stdio.h>
int main(){
printf("%d\n", - 1 + 2 - 12 * -13 / -4);
printf("%d\n", - 1 % - 2 + 12 %-13 % - 4);
printf("%d\n",-4/2 - 12/4 - 13 %-4);
printf("%d\n", (- 1 + 2 - 12) * (-13 / - 4));
printf("%d\n", (- 1 % - 2 + 12) %(-13 % - 4));
printf("%d\n", (- 4 /2 - 12) / (4 -13 % - 4));
return 0;
}