#include<stdio.h>
int main(){

    int x, y=0;
    printf("Enter the Number : \n");
    scanf("%d",&x);
    
    do{
    y=(y*10) + (x%10);
        x=x/10;
    }
    while(x!=0);

    printf("The Value of y is %d \n",y);
    return 0;
}