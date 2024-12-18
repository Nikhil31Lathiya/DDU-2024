#include<stdio.h>

int main(){

    int a = 10;

    int *p;

    p = &a;

    printf("\nA value : %d",a);
    printf("\nA address : %d\n",&a);

    printf("\nP address : %d",&p);
    printf("\nA address : %d\n",p);

    int **q;
    q = &p;
    printf("\nQ address : %d",&q);
    printf("\nP address : %d",q);

    return 0;
}