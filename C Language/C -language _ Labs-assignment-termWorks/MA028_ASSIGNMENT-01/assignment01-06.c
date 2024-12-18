#include<stdio.h>
int main(){
    int a,b,c;

    printf("Enter 1st Number : \n");
    scanf("%d",&a);
    printf("Enter 2nd Number : \n");
    scanf("%d",&b);
    printf("Enter 3rd Number : \n");
    scanf("%d",&c);

    if( (a+b) >c || (b+c) > a || (c+a) > b ){

        if((a*a) + (b*b) == (c*c) ){

            printf("Right Angle triangle : \n");
        }
        else if(a == b && b == c && c==a){
            printf("Equilateral Triangle : \n");
        }
        else if( a!=b && b!=c && c!=a){
            printf("scalene Triangle : \n");
        }
        else{
            printf("isosceles Triangle : \n");
        }
    }
    else{
        printf("This Triangle is NOT possible.\n");
    }

    return 0;
}