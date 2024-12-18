#include<stdio.h>

int main(){

    int a[5],*b[5];

    printf("Enter 5 int value : ");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }

    printf("\nValue Array : ");
    for(int i=0;i<5;i++){
        printf("\n%d",a[i]);
    }

    printf("\nAddress Array : ");
    for(int i=0;i<5;i++){
        printf("\n%d",&a[i]);
    }

    return 0;
}