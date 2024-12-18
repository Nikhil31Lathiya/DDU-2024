#include<stdio.h>
int main(){

    int i, q , r=1 , ld, fd;

    printf("Enter the Number \n");
    scanf("%d",&i);

    ld = i%10;

    while(i>=10){
        i = i/10;
    }
    printf("The sum is : %d \n" , ld+i);
    
    return 0;
}