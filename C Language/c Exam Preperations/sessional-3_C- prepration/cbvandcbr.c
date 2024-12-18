// #include<stdio.h>

//     void func(int x , int y){
//         x = 200;
//         y = 200;
//         // printf("%d",&x);
//     }

// int main()
// {   int x = 10 ;
//     int y = 20;
//     func(&x,&y);
//         // printf("%d",&x);

//     printf("%d %d",x,y);
// return 0;
// }
#include<stdio.h>
int main()
{
    // int x = 10;
    // int *p ;
    // *p ;
    
    // *p = 4;
    // printf("%d  ",*p);
    // printf("%d ", &x);

    // int i=10;
    // int *p, *q;
    // p = &i;
    // q= p;
    // printf("%d %d",*p,*q);

    int a[] = {1,3,4,4};
    int l = sizeof(a)/sizeof(a[0]);
    printf("%d ",l);
return 0;
}