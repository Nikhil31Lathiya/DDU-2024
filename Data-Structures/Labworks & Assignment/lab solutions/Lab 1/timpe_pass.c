#include<stdio.h>

int main(){
    
    int p=10;
    int *ptr = &p;

    printf("%d \n" , *ptr );

    printf("%d \n" , ptr );

    printf("%d \n" , &ptr );

    

}