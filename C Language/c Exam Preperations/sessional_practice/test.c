#include<stdio.h>
int main()
{
//  int ch= '\t';
//  if(isgraph(ch))
//     printf("ch = |%c| print");
// else
//     printf("ch = |%c| cannot");

    // int i=0;
    // for(; i<=5 ; i++)
    // printf("%d",i);

    // unsigned char i = 254;
    // for(i<=5 ; && i>=-1; ++i)
    // printf("%d",i)
    int a[5] = {'A', 'B', 'C', 'D', 'E'};
    int i,j,m;
    i= ++a[1]-60;
    j=a[1]++;
    m= a[i++];
    printf("%d %d",i,j);

return 0;
}