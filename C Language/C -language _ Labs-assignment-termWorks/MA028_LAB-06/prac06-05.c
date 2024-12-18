#include <stdio.h>

int main() {

    static int d=0 ;
    int n1,n2,c;

    printf("Enter the 1st Number  : ");
    scanf("%d",&n1);
    printf("Enter the 2nd Number :");
    scanf("%d",&n2);

    while(n1>0)
    {
        c=n1 % 10;
        c = c * (n2 %10);
        n1 = n1/10;
        n2 = n2/10;
        d+=c;
    }

    printf("The Ans is : %d " , d);
    return 0;
}
