#include<stdio.h>
int main(){

    int a,b,c, result=0;

    printf("Enter 1st Number : \n");
    scanf("%d",&a);
    printf("Enter 2nd Number : \n");
    scanf("%d",&b);
    printf("Enter 3rd Number : \n");
    scanf("%d",&c);

    if(a !=b && a != c && b != c){
        result = 1;
        printf("\n%d", result);
    }
    else{
        printf("\n%d", result);
    }

    return 0;
}