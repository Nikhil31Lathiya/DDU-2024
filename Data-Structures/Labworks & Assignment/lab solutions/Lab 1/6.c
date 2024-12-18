#include<stdio.h>
void pass_val(int a,int b)
{
    printf("\n\nBefore Swap Using Pass By Value, A -> %d, B -> %d\n",a,b);
    int c= a;
    a = b;
    b = c;
    printf("\nAfter Swap Using Pass By Value, A -> %d, B -> %d",a,b);
}

void pass_ref(int *a, int *b)
{
    printf("\n\nBefore Swap Using Pass By Reference, A -> %d, B -> %d",*a,*b);
    int c = *a;
    *a = *b;
    *b = *(&c);
    printf("\n\nAfter Swap Using Pass By Reference, A -> %d, B -> %d",*a,*b);
}

int main()
{
    int a=5,b=6;
    pass_val(a,b);
    pass_ref(&a,&b);
    return 0;
}